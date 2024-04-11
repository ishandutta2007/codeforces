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

const int N = (int)1e6 + 50;

struct SuffixArray {
    vi sa, lcp, rank;
    SuffixArray(basic_string<int>& s, int lim=256) { // or basic_string<int>
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


int ncnt = 1; // Need to initialize before every test case!

struct node{
    int ls, rs;
    pii mx;
} ns[N * 20];

int newnode(pii mx){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].mx = mx;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].mx = max(ns[ls].mx, ns[rs].mx);
    return ncnt++;
}
int build(int pos, int tl, int tr){
    if(tl == tr) return newnode({1, -pos});
    int mid = (tl + tr) / 2;
    if(pos <= mid) return newnode(build(pos, tl, mid), 0);
    else return newnode(0, build(pos, mid + 1, tr));
}

int merge(int u, int v, int tl, int tr) {
    if(!u || !v) return u | v;
    if(tl == tr) {
        ns[u].mx.first += ns[v].mx.first;
        return u;
    }
    int mid = (tl + tr) / 2;
    ns[u].ls = merge(ns[u].ls, ns[v].ls, tl, mid);
    ns[u].rs = merge(ns[u].rs, ns[v].rs, mid + 1, tr);
    ns[u].mx = max(ns[ns[u].ls].mx, ns[ns[u].rs].mx);
    return u;
}


pii qmax(int v, int l, int r, int tl, int tr){
    if(v == 0 || tr < l || tl > r) return pii{-1, 0};
    if(l <= tl && tr <= r) return ns[v].mx;
    int tm = (tl + tr) / 2;
    return max(qmax(ns[v].ls, l, r, tl, tm), qmax(ns[v].rs, l, r, tm + 1, tr));
}

string str;
int pos[N];
int m, q;
string s[(int)5e4 + 5];
int f[N ];
int tr[N];
pii res[N];

struct Qr {
    int l, r, pl, idx;
};

vector<int> upd[N];
vector<Qr> qrs[N];

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
void unite(int u, int v) {
    u = find(u), v = find(v);
    tr[v] = merge(tr[u], tr[v], 0, m - 1);
    f[u] = v;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ns[0].mx = {-1, 0};

    basic_string<int> ms;
    cin >> str;
    rep(i, 0, sz(str)) {
        pos[sz(ms)] = -1;
        ms.push_back(str[i] - 'a' + 1);
    }
    int c = 27;

    cin >> m;
    rep(i, 0, m) {
        pos[sz(ms)] = -2;
        ms.push_back(c++);
        cin >> s[i];
        rep(j, 0, sz(s[i])) {
            pos[sz(ms)] = i;
            ms.push_back(s[i][j] - 'a' + 1);
        }
    }
    SuffixArray sa(ms, c);
    
    cin >> q;
    rep(i, 0, q) {
        int l, r, pl, pr; cin >> l >> r >> pl >> pr;
        l--, r--, pl--, pr--;
        qrs[pr - pl + 1].push_back({l, r, pl, i});
    }

    rep(i, 1, sz(ms)) {
        upd[sa.lcp[i]].push_back(i - 1);
    }

    rep(i, 1, sz(ms) + 1) {
        f[i] = i;
        if(pos[sa.sa[i]] >= 0) tr[i] = build(pos[sa.sa[i]], 0, m - 1);
    }
    for (int i = sz(ms); i >= 0; i--) {
        for (int j : upd[i]) {
            unite(j, j + 1);
        }
        for (auto &qr : qrs[i]) {
            res[qr.idx] = max(pii{0, -qr.l}, qmax(tr[find(sa.rank[qr.pl])], qr.l, qr.r, 0, m - 1));
        }
    }

    rep(i, 0, q) {
        cout <<  -res[i].second + 1 << " " <<  res[i].first<< '\n';
    }
}