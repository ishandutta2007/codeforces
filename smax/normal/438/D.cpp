#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 100000

int a[MAXN];
long long mx[4*MAXN], mn[4*MAXN], sum[4*MAXN], lazy[4*MAXN];

void build(int p, int l, int r) {
    if (l == r) {
        mx[p] = mn[p] = sum[p] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    mx[p] = max(mx[2*p], mx[2*p+1]);
    mn[p] = min(mn[2*p], mn[2*p+1]);
    sum[p] = sum[2*p] + sum[2*p+1];
}

void push(int p, int l, int r) {
    if (lazy[p]) {
        mx[p] += lazy[p];
        mn[p] += lazy[p];
        sum[p] += (r - l + 1) * lazy[p];
        DEBUG(sum[p], l, r)
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

long long query(int p, int l, int r, int i, int j) {
    push(p, l, r);

    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j)
        return sum[p];

    int m = (l + r) / 2;
    return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

void down(int p, int l, int r, int x) {
    push(p, l, r);

    if (mx[p] < x)
        return;
    if (mn[p] == mx[p]) {
        long long val = mx[p] - mx[p] % x;
        mx[p] -= val;
        mn[p] -= val;
        sum[p] -= (r - l + 1) * val;
        if (l != r) {
            lazy[2*p] -= val;
            lazy[2*p+1] -= val;
        }
        return;
    }

    int m = (l + r) / 2;
    down(2*p, l, m, x);
    down(2*p+1, m+1, r, x);
    mx[p] = max(mx[2*p], mx[2*p+1]);
    mn[p] = min(mn[2*p], mn[2*p+1]);
    sum[p] = sum[2*p] + sum[2*p+1];
}

void updateMod(int p, int l, int r, int i, int j, int x) {
    push(p, l, r);

    if (i > r || j < l || mx[p] < x)
        return;
    if (i <= l && r <= j) {
        down(p, l, r, x);
        return;
    }

    int m = (l + r) / 2;
    updateMod(2*p, l, m, i, j, x);
    updateMod(2*p+1, m+1, r, i, j, x);
    mx[p] = max(mx[2*p], mx[2*p+1]);
    mn[p] = min(mn[2*p], mn[2*p+1]);
    sum[p] = sum[2*p] + sum[2*p+1];
}

void updateSet(int p, int l, int r, int k, int x) {
    DEBUG(p, l, r, k, x)
    push(p, l, r);

    if (l == r) {
        mx[p] = mn[p] = sum[p] = x;
        DEBUG(l, r, sum[p], x)
        return;
    }

    int m = (l + r) / 2;
    if (k <= m) {
        updateSet(2*p, l, m, k, x);
        push(2*p+1, m+1, r);
    } else {
        push(2*p, l, m);
        updateSet(2*p+1, m+1, r, k, x);
    }
    mx[p] = max(mx[2*p], mx[2*p+1]);
    mn[p] = min(mn[2*p], mn[2*p+1]);
    sum[p] = sum[2*p] + sum[2*p+1];
    DEBUG(sum[p], l, r, k, x)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];

    build(1, 0, n-1);
    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1) << "\n";
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            updateMod(1, 0, n-1, l-1, r-1, x);
        } else {
            int k, x;
            cin >> k >> x;
            updateSet(1, 0, n-1, k-1, x);
        }
    }

    return 0;
}