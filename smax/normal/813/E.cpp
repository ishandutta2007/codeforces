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

const int MAX = 4e6 + 5;

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

int query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j)
        return st[p];

    int m = (l + r) / 2;
    return query(pl[p], l, m, i, j) + query(pr[p], m+1, r, i, j);
}

int update(int p, int l, int r, int idx, int val) {
    if (l == r)
        return newLeaf(st[p] + val);

    int m = (l + r) / 2;
    if (idx <= m)
        return newParent(update(pl[p], l, m, idx, val), pr[p]);
    return newParent(pl[p], update(pr[p], m+1, r, idx, val));
}

int root[100005];
deque<int> dq[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        dq[a].push_back(i);
        root[i+1] = update(root[i], 1, n, i + 1, 1);
        if ((int) dq[a].size() > k) {
            root[i+1] = update(root[i+1], 1, n, dq[a].front() + 1, -1);
            dq[a].pop_front();
        }
    }

    int q;
    cin >> q;
    int last = 0;
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        x = (x + last) % n + 1;
        y = (y + last) % n + 1;
        if (x > y)
            swap(x, y);
        cout << (last = query(root[y], 1, n, x, y)) << "\n";
    }

    return 0;
}