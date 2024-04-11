#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)4e5 + 50, LOGN = 19;

struct SuffixArray {
    vi sa, lcp, rk;
    vi mm;
    vector<vector<int>> st;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = rk = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
        s = " " + s;
        for(int i = n - 1; i >= 1; i--) sa[i]++, rk[sa[i]] = i;

        mm = vi(n, 0);
        mm[0] = -1;
        st = vector<vector<int> > ((int)log2(n) + 1, vector<int> (n, 0));
        for(int i = 1; i < n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = lcp[i];
        }
        for(int lg = 1; lg <= (int)(log2(n)); lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    int rmq(int a, int b){
//        cout << "getting " << a << " " << b << endl;
        int l = rk[a], r = rk[b];
        if(l == r) return N;
        if(l > r) swap(l, r);
        l++;
        int k = mm[r - l + 1];
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }
};

int n;
string s, t;
string rev;
vector<int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;
    SuffixArray sa(s);

    pos.push_back(0);
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            pos.push_back(i);
            t += (i % 2 == 0 ? '0' : '1');
        }
    }
    rev = t;
    for(char &c : rev) {
        if(c == '0') c = '1';
        else c = '0';
    }
    t += rev;
    SuffixArray st(t);
    int q;
    cin >> q;
    while(q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        int al = (int)(lower_bound(all(pos), l1) - pos.begin());
        int ar = (int)(lower_bound(all(pos), l1 + len) - pos.begin());
        int bl = (int)(lower_bound(all(pos), l2) - pos.begin());
        int br = (int)(lower_bound(all(pos), l2 + len) - pos.begin());
        if(ar - al != br - bl) {
            cout << "No\n";
        }
        else if(al == ar) {
            cout << "Yes\n";
        } else {
            if(l1 % 2 == l2 % 2) cout << (st.rmq(al, bl) >= br - bl ? "Yes\n" : "No\n");
            else cout << (st.rmq(al, bl + (int)rev.size()) >= br - bl ? "Yes\n" : "No\n");
        }
    }
}