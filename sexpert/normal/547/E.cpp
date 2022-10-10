#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 4e5 + 10;
const int LOG = 18;

int sa[MAXN], lcp[MAXN], ps[MAXN], sa_pos[MAXN], owner[MAXN], start[MAXN], len[MAXN], ar[MAXN], N, q;
int mn[LOG][MAXN], le[MAXN], ri[MAXN];
string s;
array<int, 2> rk[MAXN];

void build_sa() {
    int n = s.size();
    for(int i = 0; i < n; i++) {
        rk[i] = {s[i], (i + 1 < n) ? s[i + 1] : -1};
        sa[i] = i;
    }
    for(int k = 2; ; k *= 2) {
        sort(sa, sa + n, [&](int i, int j){ return rk[i] < rk[j]; });
        int cur = 0;
        for(int i = 0; i < n; i++) {
            ps[sa[i]] = cur;
            if(rk[sa[i]] != rk[sa[i + 1]])
                cur++;
        }
        if(ps[sa[n - 1]] == n - 1)
            break;
        for(int i = 0; i < n; i++)
            rk[i] = {ps[i], (i + k < n) ? ps[i + k] : -1};
    }
}

int rmq(int L, int R) {
    if(L > R)
        return 1e9 + 7;
    int l = __lg(R - L + 1);
    return min(mn[l][L], mn[l][R - (1 << l) + 1]);
}

void build_lcp() {
    int n = s.size();
    for(int i = 0; i < n; i++)
        sa_pos[sa[i]] = i;

    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur = max(cur, 0);
        if(sa_pos[i] == 0) {
            cur = 0;
            continue;
        }
        int j = sa[sa_pos[i] - 1];
        while(i + cur < n && j + cur < n && s[i + cur] == s[j + cur])
            cur++;
        lcp[sa_pos[i]] = cur--;
    }
}

struct wnode {
    int lo, hi;
    wnode *left, *right;
    vector<int> cleft;

    wnode(int *st, int *en, int lo, int hi) : lo(lo), hi(hi) {
        if(st == en || lo == hi) return;
        int mi = (lo + hi)/2;
        auto f = [mi](int x) { return x <= mi; };
        cleft.push_back(0);
        for(auto it = st; it != en; ++it) cleft.push_back(cleft.back() + f(*it));
        auto it = stable_partition(st, en, f);
        left = new wnode(st, it, lo, mi);
        right = new wnode(it, en, mi + 1, hi);
    }

    int count(int L, int R, int X, int Y) {
        if(Y < lo || hi < X) return 0;
        if(X <= lo && hi <= Y) return R - L + 1;
        int mi = (lo + hi)/2;
        int izq = cleft[L - 1], der = cleft[R];
        return left->count(izq + 1, der, X, Y) + right->count(L - izq, R - der, X, Y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> q;
    int cur = 0;
    for(int i = 1; i <= N; i++) {
        string t;
        cin >> t;
        s += t;
        s += '$';
        start[i] = cur;
        len[i] = t.length();
        for(int j = cur; j < cur + t.size(); j++)
            owner[j] = i;
        cur += t.size() + 1;
    }

    int n = s.size();
    build_sa();
    build_lcp();
    /*for(int i = 1; i < n; i++)
        cout << lcp[i] << " ";
    cout << '\n';*/

    lcp[0] = n + 1;
    for(int i = 0; i < n; i++)
        mn[0][i] = lcp[i];
    for(int l = 0; l + 1 < LOG; l++)
        for(int i = 0; i < n; i++)
            mn[l + 1][i] = min(mn[l][i], mn[l][min(n, i + (1 << l))]);
    
    for(int i = 1; i <= N; i++) {
        int st = sa_pos[start[i]], length = len[i];
        int lo = st, hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(rmq(st + 1, mi) >= length)
                lo = mi;
            else
                hi = mi - 1;
        }
        ri[i] = lo;
        lo = 0, hi = st;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(rmq(mi + 1, st) >= length)
                hi = mi;
            else
                lo = mi + 1;
        }
        le[i] = lo;
    }
    cout.flush();

    for(int i = 0; i < n; i++)
        ar[i] = owner[sa[i]];
    wnode tree(ar, ar + n, 0, N);
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        //cout << le[k] + 1 << " " << ri[k] + 1 << " " << l << " " << r << '\n';
        cout << tree.count(le[k] + 1, ri[k] + 1, l, r) << '\n';
    }
}