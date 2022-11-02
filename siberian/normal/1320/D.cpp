#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

mt19937 rnd(time(0));

const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int base = rnd() % 1000 + 228 + 1337;

int add(int a, int b) {
    a += b;
    if (a >= MOD) 
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int pows[MAXN];

void build() {
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pows[i] = mul(pows[i - 1], base);
    }
}

struct node{
    int hash, cnt;
    int L, R;
    node() {
        hash = 0;
        cnt = -1;
        L = 0;
        R = 0;
    }
    node(char x) {
        if (x == '0') {
            hash = 0, cnt = 1, L = 0, R = 0;
        }
        else {
            hash = 1, cnt = 0, L = 1, R = 1;
        }
    }
};

bool operator==(const node & a, const node & b) {
    return tie(a.hash, a.cnt, a.L, a.R) == tie(b.hash, b.cnt, b.L, b.R);
}

node merge(node L, node R) {
    if (L.cnt == -1) return R;
    if (R.cnt == -1) return L;
    node ans;
    ans.L = L.L;
    ans.R = R.R;
    ans.cnt = L.cnt + R.cnt;
    ans.hash = add(L.hash, mul(R.hash, pows[L.cnt]));
    if (L.R && R.L) ans.hash = sub(ans.hash, mul(2, pows[L.cnt]));
    if (L.cnt == 0) {
        if (R.cnt == 0) {
            node ans;
            ans.cnt = 0;
            ans.hash = L.L ^ R.L;
            ans.L = L.L ^ R.L;
            ans.R = L.L ^ R.L;
            return ans;
        }
        ans.L = L.L ^ R.L;
    }
    else if (R.cnt == 0) {
        ans.R = L.R ^ R.R;
    } 
    return ans;
}

struct segment_tree{
    vector<node> tree;
    int n;
    
    segment_tree() {}

    void build(int v, int tl, int tr, const string & s) {
        if (tl == tr - 1) {
            tree[v] = node(s[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, s);
        build(v * 2 + 1, tm, tr, s);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    segment_tree(const string & s) {
        n = s.size();
        tree.assign(n * 4, {});
        build(1, 0, n, s);
    }

    node get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return node();
        if (tl >= l && tr <= r)
            return tree[v];
        int tm = (tl + tr) / 2;
        return merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
    }

    node get(int l, int r) {
        return get(1, 0, n, l, r + 1);
    }
};

int n;
string s;

void read() {
    cin >> n >> s;
}

vector<bool> ans;

void run() {    
    build();
    segment_tree tree(s);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--, l2--;
        auto L = tree.get(l1, l1 + len - 1);
        auto R = tree.get(l2, l2 + len - 1);
        ans.push_back(L == R);
    }
}

void write() {
    for (auto i : ans) {
        if (i) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}