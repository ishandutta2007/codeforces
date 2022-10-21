#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;



struct SuffixArray {
    vi sa, lcp, rank;
    SuffixArray(basic_string<int> &s, int lim=256) { // or
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim));
        x.back() = 0; // if basic_string<int>
        sa = lcp = rank = y, iota(all(sa), 0);
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
    }
};

const int N = (int)6e5 + 50;

int n;
string s[N];
int val[N];
ll cost[N];
int f[N];

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return ;
    f[u] = v;
    cost[v] += cost[u];
}

int len[N];
vi add[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    basic_string<int> str;
    int m = 26;
    rep(i, 0, n) {
        cin >> s[i];
    }
    rep(i, 0, n) cin >> val[i];
    rep(i, 0, n) {
        for (int j = 0; j < sz(s[i]); j++) {
            char c = s[i][j];
            cost[sz(str)] = val[i];
            len[sz(str)] = sz(s[i]) - j;
            str.push_back(c - 'a' + 1);
        }
        cost[sz(str)] = 0;
        str.push_back(++m);
    }
    SuffixArray sa(str, m + 1);
    ll res = 0;

    int tn = sz(str);
    rep(i, 0, tn) {
        int pos = sa.rank[i];
        if((pos == 0 || sa.lcp[pos] < len[i]) && (pos == tn - 1 || sa.lcp[pos + 1] < len[i])) {
            res = max(res, cost[i] * len[i]);
        }
    }
    rep(i, 1, sz(str)) {
        add[sa.lcp[i]].push_back(i);
    }
    iota(f, f + tn, 0);
    for (int i = N - 1; i >= 0; i--) {
        for (int pos : add[i]) {
            unite(sa.sa[pos - 1], sa.sa[pos]);
        }
        for (int pos : add[i]) {
            res = max(res, 1LL * i * cost[find(sa.sa[pos])]);
        }
    }
    cout << res << '\n';



}