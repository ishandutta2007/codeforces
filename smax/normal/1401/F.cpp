#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define LOG 19

struct Node {
    int k;
    vector<int> lazy;
    long long ans;
    Node *l, *r;

    Node(int _k) : k(_k), lazy(LOG), ans(0), l(NULL), r(NULL) {}
};

void push(Node *p) {
    if (!p) return;
    if (p->lazy[p->k])
        swap(p->l, p->r);
    for (int i=0; i<LOG; i++) {
        if (p->l) p->l->lazy[i] ^= p->lazy[i];
        if (p->r) p->r->lazy[i] ^= p->lazy[i];
        p->lazy[i] = false;
    }
}

long long query(Node *p, int l, int r, int i, int j) {
    push(p);
    if (i > r || j < l || !p)
        return 0;
    if (i <= l && r <= j)
        return p->ans;
    int m = (l + r) / 2;
    return query(p->l, l, m, i, j) + query(p->r, m+1, r, i, j);
}

void update(Node *p, int l, int r, int idx, int val) {
    push(p);
    if (l == r) {
        p->ans = val;
        return;
    }
    int m = (l + r) / 2;
    if (idx <= m) {
        if (!p->l) p->l = new Node(p->k - 1);
        update(p->l, l, m, idx, val);
    } else {
        if (!p->r) p->r = new Node(p->k - 1);
        update(p->r, m+1, r, idx, val);
    }
    p->ans = (p->l ? p->l->ans : 0) + (p->r ? p->r->ans : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    Node st(n);
    for (int i=0; i<1<<n; i++) {
        int a;
        cin >> a;
        update(&st, 0, (1<<n)-1, i, a);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, k;
            cin >> x >> k;
            update(&st, 0, (1<<n)-1, x-1, k);
        } else if (type == 2) {
            int k;
            cin >> k;
            for (int i=0; i<=k; i++)
                st.lazy[i] ^= true;
        } else if (type == 3) {
            int k;
            cin >> k;
            st.lazy[k+1] ^= true;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(&st, 0, (1<<n)-1, l-1, r-1) << "\n";
        }
    }

    return 0;
}