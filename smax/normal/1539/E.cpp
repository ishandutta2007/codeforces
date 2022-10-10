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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Node {
    int ans = 0, lazy = -1, l, r;

    void leaf(int val) {
        ans = val;
    }

    void pull(const Node &a, const Node &b) {
        ans = a.ans + b.ans;
    }

    void push(int val) {
        lazy = val;
    }

    void apply() {
        ans = (r - l + 1) * lazy;
        lazy = -1;
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy != -1) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    Node query(int p, int i, int j) {
        push(p);
        if (st[p].l == i && st[p].r == j)
            return st[p];
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            return query(2*p, i, j);
        else if (i > m)
            return query(2*p+1, i, j);
        Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    int query(int i, int j) {
        return query(1, i, j).ans;
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        if (i > j) return;
        update(1, i, j, val);
    }

    int get(int p, int i, int j) {
        push(p);
        if (i > st[p].r || j < st[p].l || st[p].ans == 0)
            return -1;
        if (st[p].l == st[p].r)
            return st[p].l;
        int ret = get(2*p, i, j);
        if (ret == -1)
            ret = get(2*p+1, i, j);
        return ret;
    }

    int get(int i, int j) {
        return get(1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> k(n + 1), al(n + 1), bl(n + 1), ar(n + 1), br(n + 1), compress{0};
    for (int i=1; i<=n; i++) {
        cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];
        compress.push_back(k[i]);
        compress.push_back(al[i]);
        compress.push_back(bl[i]);
        compress.push_back(ar[i]);
        compress.push_back(br[i]);
    }

    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    int o = (int) compress.size();

    auto get = [&] (int x) -> int {
        return int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
    };

    vector<SegmentTree> dp(2, o);
    vector<vector<array<int, 6>>> par(2, vector<array<int, 6>>(1));
    dp[0].update(0, 0, 1);
    dp[1].update(0, 0, 1);
    for (int i=1; i<=n; i++) {
        k[i] = get(k[i]);
        al[i] = get(al[i]);
        bl[i] = get(bl[i]);
        ar[i] = get(ar[i]);
        br[i] = get(br[i]);
        int rep0 = dp[0].get(0, o-1), rep1 = dp[1].get(0, o-1);
        // dp[0][x] -> dp[0][x]
        if (ar[i] <= k[i] && k[i] <= br[i]) {
            dp[0].update(0, al[i]-1, 0);
            dp[0].update(bl[i]+1, o-1, 0);
            par[0].push_back({0, 1, -1, -1, -1, -1});
        } else {
            dp[0].update(0, o-1, 0);
            par[0].push_back({-1, -1, -1, -1, -1, -1});
        }
        // dp[1][x] -> dp[1][x]
        if (al[i] <= k[i] && k[i] <= bl[i]) {
            dp[1].update(0, ar[i]-1, 0);
            dp[1].update(br[i]+1, o-1, 0);
            par[1].push_back({1, 0, -1, -1, -1, -1});
        } else {
            dp[1].update(0, o-1, 0);
            par[1].push_back({-1, -1, -1, -1, -1, -1});
        }
        // dp[0][x] -> dp[1][last]
        if (al[i] <= k[i] && k[i] <= bl[i] && ar[i] <= k[i-1] && k[i-1] <= br[i] && rep0 != -1) {
            dp[1].update(k[i-1], k[i-1], 1);
            par[1].back()[2] = 0;
            par[1].back()[3] = 0;
            par[1].back()[4] = rep0;
            par[1].back()[5] = k[i-1];
        }
        // dp[1][x] -> dp[0][last]
        if (ar[i] <= k[i] && k[i] <= br[i] && al[i] <= k[i-1] && k[i-1] <= bl[i] && rep1 != -1) {
            dp[0].update(k[i-1], k[i-1], 1);
            par[0].back()[2] = 1;
            par[0].back()[3] = 1;
            par[0].back()[4] = rep1;
            par[0].back()[5] = k[i-1];
        }
    }

    int side = -1;
    if (dp[0].st[1].ans)
        side = 0;
    else if (dp[1].st[1].ans)
        side = 1;
    if (side == -1) {
        cout << "No\n";
        return 0;
    }

    int cur = dp[side].get(0, o-1);
    vector<int> ret;
    for (int i=n; i>0; i--) {
        auto [nxt0, dir0, nxt1, dir1, from, y] = par[side][i];
        if (cur == y) {
            assert(dir1 != -1);
            ret.push_back(dir1);
            side = nxt1;
            cur = from;
        } else {
            assert(dir0 != -1);
            ret.push_back(dir0);
            side = nxt0;
        }
    }
    reverse(ret.begin(), ret.end());

    cout << "Yes\n";
    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}