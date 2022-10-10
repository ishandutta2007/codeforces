#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 2e7 + 5;

int id = 1, pl[MAX], pr[MAX], st[MAX];

int newLeaf(int val) {
    int p = id++;
    pl[p] = pr[p] = 0;
    st[p] = val;
    return p;
}

int newParent(int a, int b) {
    int p = id++;
    pl[p] = a;
    pr[p] = b;
    st[p] = st[a] + st[b];
    return p;
}

int build(int *a, int l, int r) {
    if (l == r)
        return newLeaf(a[l]);
    int m = (l + r) / 2;
    return newParent(build(a, l, m), build(a, m+1, r));
}

// int query(int p, int l, int r, int i, int j) {
//     if (i > r || j < l)
//         return 0;
//     if (i <= l && r <= j)
//         return st[p];
//     int m = (l + r) / 2;
//     return query(pl[p], l, m, i, j) + query(pr[p], m+1, r, i, j);
// }

int query(int pa, int pb, int l, int r, int k) {
    if (l == r)
        return l;
    int m = (l + r) / 2, ret = -1;
    if (st[pl[pb]] - st[pl[pa]] > k)
        ret = query(pl[pa], pl[pb], l, m, k);
    if (ret == -1 && st[pr[pb]] - st[pr[pa]] > k)
        ret = query(pr[pa], pr[pb], m+1, r, k);
    return ret;
}

int update(int p, int l, int r, int idx, int val) {
    if (l == r)
        return newLeaf(st[p] + val);
    int m = (l + r) / 2;
    if (idx <= m)
        return newParent(update(pl[p], l, m, idx, val), pr[p]);
    return newParent(pl[p], update(pr[p], m+1, r, idx, val));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> root(n + 1);
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        root[i] = update(root[i-1], 1, n, a, 1);
    }

    for (int i=0; i<q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(root[l-1], root[r], 1, n, (r - l + 1) / k) << "\n";
    }

    return 0;
}