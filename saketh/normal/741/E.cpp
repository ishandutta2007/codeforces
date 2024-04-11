#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct suffix_array{
    const int INF = 0x7fffffff;

    int L, D;
    string str;
    vector<vector<int> > suff;
    vector<int> rank_of, at_rank;

    pair<pair<int, int>, int> __make_rep(int l, int i, int p){
        if(!l) return {{str[i], INF}, i};
        return {{suff[l-1][i], (i+p<L) ? suff[l-1][i+p] : INF}, i};
    }

    suffix_array(string _str){
        str = _str;
        L = str.size();
        D = 33 - __builtin_clz(L-1);
        suff.resize(D);

        vector<pair<pair<int, int>, int> > keys(L);
        for(int l=0; l<D; l++){
            for(int i=0; i<L; i++)
                keys[i] = __make_rep(l, i, 1<<(l-1));
            sort(keys.begin(), keys.end());
            
            suff[l].resize(L);
            for(int i=0, r=0; i<L; i++){
                if(i>0 && keys[i].first != keys[i-1].first) r++;
                suff[l][keys[i].second] = r;
            }
        }

        rank_of.resize(L);
        at_rank.resize(L);
        for(int i=0; i<L; i++){
            rank_of[i] = suff.back()[i];
            at_rank[rank_of[i]] = i;
        }
    }

    // compare the string at [i, i+l1) to the string at [j, j+l2) 
    int comp(int i, int l1, int j, int l2){
        int cl = min(l1, l2);
        for(int l=0; l<D; l++)
            if((cl>>l)&1){
                if(suff[l][i] != suff[l][j]) 
                    return suff[l][i] < suff[l][j] ? -1 : 1;
                i += 1<<l, j += 1<<l;
            }

        return (l1!=l2) ? (l1<l2) ? -1 : 1 : 0;
    }
};

int adj(int ins, int inx, int len, int N, int M) {
    if (inx < ins) return inx;
    if (inx >= ins + M) return inx - M;
    return N + inx - ins;
}

struct RMQ {
    vvi mv;
    RMQ (vi &_vals) {
        int N = _vals.size();
        mv.push_back(_vals);

        int pw2 = 1;
        for (int l = 1; pw2 <= N; l++) {
            pw2 *= 2;
            vi nxt = mv.back();
            for (int i = 0; i < N; i++) {
                int inx = i + (1 << (l-1));
                if (inx < N) nxt[i] = min(nxt[i], mv.back()[inx]);
            }
            mv.push_back(nxt);
        }
    }

    int read(int i, int j) {
        if (i > j) return INT_MAX;
        int len = j - i + 1;
        int pw2 = 1, lvl = 0;
        while (pw2 * 2 <= len) {
            pw2 *= 2;
            lvl++;
        }
        return min(mv[lvl][i], mv[lvl][j - pw2 + 1]);
    }
};

const int LIM = 250;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();

    stringstream st;
    st << S << T;

    suffix_array sa(st.str());

    vi opts(N + 1);
    for (int i = 0; i <= N; i++)
        opts[i] = i;

    TRACE( vi opts2 = opts;
    stable_sort(all(opts2), [&](int i, int j) {
        stringstream s1, s2;
        if (i) s1 << S.substr(0, i);
        if (j) s2 << S.substr(0, j);
        s1 << T;
        s2 << T;
        s1 << S.substr(i);
        s2 << S.substr(j);

        return s1.str() < s2.str();
    }); )

    stable_sort(all(opts), [&](int i, int j) {
        vi pts = { 0, i, j, i + M, j + M, M + N };
        sort(all(pts));
        pts.erase(unique(all(pts)), pts.end());

        for (int k = 0; k + 1 < pts.size(); k++) {
            int inx = pts[k], len = pts[k+1] - pts[k];
            int res = sa.comp(adj(i, inx, len, N, M), len,
                              adj(j, inx, len, N, M), len);
            if (res != 0) return res == -1;
        }

        return false;
    });

    TRACE(assert(opts == opts2);)

    vi rank(N + 1);
    for (int i = 0; i <= N; i++) {
        rank[opts[i]] = i;
    }

    WATCHC(opts);
    WATCHC(rank);
    RMQ whole(rank);

    int Q;
    cin >> Q;

    vi l(Q), r(Q), k(Q), x(Q), y(Q), ans(Q, INT_MAX);
    vvi which(LIM);

    for (int q = 0; q < Q; q++) {
         cin >> l[q] >> r[q] >> k[q] >> x[q] >> y[q];
         x[q] = min(x[q], k[q] - 1);
         y[q] = min(y[q], k[q] - 1);

         if (k[q] >= LIM) {
            for (int g = 0; g <= N; g += k[q]) {
                int gx = g + x[q], gy = g + y[q];
                gx = max(gx, l[q]);
                gy = min(gy, r[q]);
                if (gx <= gy)
                    ans[q] = min(ans[q], whole.read(gx, gy));
            }
         } else {
             which[k[q]].push_back(q);
         }
    }

    for (int siz = 1; siz < LIM; siz++) {
        if (!which[siz].size()) continue;

        vector<RMQ> small;
        for (int rem = 0; rem < siz; rem++) {
            vi elts;
            for (int i = rem; i <= N; i += siz)
                elts.push_back(rank[i]);
            small.push_back(RMQ(elts));
        }

        for (int q : which[siz]) {
            for (int rem = x[q]; rem <= y[q]; rem++) {
                int a = (l[q] % k[q] <= rem) ? l[q]/k[q] : (l[q]/k[q]+1);
                int b = (r[q] % k[q] >= rem) ? r[q]/k[q] : (r[q]/k[q]-1);
                ans[q] = min(ans[q], small[rem].read(a, b));
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << (ans[i] == INT_MAX ? -1 : opts[ans[i]]) << " ";
    }
    cout << endl;
    return 0;
}