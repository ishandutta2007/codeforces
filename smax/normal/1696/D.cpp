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

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

template<typename T>
struct RMQ2 {
    vector<vector<T>> spt;

    RMQ2(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = max(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return max(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct SegmentTree {
    struct Node {
        int mn, mx;

        void leaf(int val) {
            mn = mx = val;
        }

        void pull(const Node &a, const Node &b) {
            mn = min(a.mn, b.mn);
            mx = max(a.mx, b.mx);
        }
    };

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
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    // Node query(int p, int l, int r, int i, int j) {
    //     if (l == i && r == j)
    //         return st[p];
    //     int m = (l + r) / 2;
    //     if (j <= m)
    //         return query(2*p, l, m, i, j);
    //     else if (i > m)
    //         return query(2*p+1, m+1, r, i, j);
    //     Node ret, ls = query(2*p, l, m, i, m), rs = query(2*p+1, m+1, r, m+1, j);
    //     ret.pull(ls, rs);
    //     return ret;
    // }

    // int query(int i, int j) {
    //     return query(1, 0, n-1, i, j).ans;
    // }

    // void update(int p, int l, int r, int idx, int val) {
    //     if (l == r) {
    //         st[p].leaf(val);
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     if (idx <= m)
    //         update(2*p, l, m, idx, val);
    //     else
    //         update(2*p+1, m+1, r, idx, val);
    //     st[p].pull(st[2*p], st[2*p+1]);
    // }

    // void update(int idx, int val) {
    //     update(1, 0, n-1, idx, val);
    // }

    int goGet(int p, int l, int r, int i, int j, int x, bool t, bool left) {
        if (i > r || j < l || (t && st[p].mx < x) || (!t && st[p].mn > x))
            return -1;
        if (l == r)
            return l;
        int m = (l + r) / 2, ret = left ? goGet(2 * p, l, m, i, j, x, t, left) : goGet(2 * p + 1, m + 1, r, i, j, x, t, left);
        if (ret == -1)
            ret = left ? goGet(2 * p + 1, m + 1, r, i, j, x, t, left) : goGet(2 * p, l, m, i, j, x, t, left);
        return ret;
    }

    void kill(int p, int l, int r, int i) {
        if (l == r) {
            st[p].mn = INT_MAX;
            st[p].mx = INT_MIN;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            kill(2 * p, l, m, i);
        else
            kill(2 * p + 1, m + 1, r, i);
        st[p].pull(st[2*p], st[2*p+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        // vector<int> mxStk, mnStk;
        // vector<vector<int>> adj(n);
        // for (int i=0; i<n; i++) {
        //     while (!mxStk.empty() && a[mxStk.back()] < a[i])
        //         mxStk.pop_back();
        //     while (!mnStk.empty() && a[mnStk.back()] > a[i])
        //         mnStk.pop_back();
        //     int mxIdx = mxStk.empty() ? -1 : mxStk.back(), mnIdx = mnStk.empty() ? -1 : mnStk.back();
        //     // consider a_i as min
        //     if (mxIdx != -1 && mxIdx > mnIdx) {
        //         adj[i].push_back(mxIdx);
        //         adj[mxIdx].push_back(i);
        //     }
        //     // consider a_i as max
        //     if (mnIdx != -1 && mnIdx > mxIdx) {
        //         adj[i].push_back(mnIdx);
        //         adj[mnIdx].push_back(i);
        //     }
        //     mxStk.push_back(i);
        //     mnStk.push_back(i);
        // }
        // DEBUG(adj);

        // // up/down, left/right
        // vector dist(n, vector<int>(4, INT_MAX));
        // deque<tuple<int, int, int>> dq;
        // dq.emplace_back(dist[0][0] = 0, 0, 0);
        // dq.emplace_back(dist[0][1] = 0, 0, 1);
        // while (!dq.empty()) {
        //     auto [d, u, mode] = dq.front();
        //     dq.pop_front();
        //     if (d > dist[u][mode])
        //         continue;
        //     bool down = mode & 1, right = mode & 2;
        //     DEBUG(d, u, down, right);
        //     for (int v : adj[u]) {
        //         int nd = d + !((a[v] < a[u]) == down && (v > u) == right);
        //         if (nd < dist[v][(a[v] < a[u]) + 2 * (v > u)]) {
        //             if (d == nd)
        //                 dq.emplace_front(dist[v][(a[v] < a[u]) + 2 * (v > u)] = nd, v, (a[v] < a[u]) + 2 * (v > u));
        //             else
        //                 dq.emplace_back(dist[v][(a[v] < a[u]) + 2 * (v > u)] = nd, v, (a[v] < a[u]) + 2 * (v > u));
        //         }
        //     }
        // }
        // cout << *min_element(dist[n-1].begin(), dist[n-1].end()) << "\n";

        // set<int> st;
        // for (int i=0; i<n; i++)
        //     st.insert(i);

        RMQ<int> rmq(a);
        RMQ2<int> rmq2(a);
        SegmentTree st(a);
        st.kill(1, 0, n - 1, 0);

        auto valid = [&] (int i, int j) -> bool {
            int mn = rmq.query(i, j), mx = rmq2.query(i, j);
            return (a[i] == mn && a[j] == mx) || (a[i] == mx && a[j] == mn);
        };

        vector<int> dist(n, -1);
        queue<int> que;
        dist[0] = 0;
        que.push(0);
        // st.erase(0);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            DEBUG(u, dist[u]);
            // u is min, go left
            int last = u;
            while (last > 0) {
                int x = st.goGet(1, 0, n - 1, 0, last - 1, a[last], true, false);
                DEBUG(u, x);
                if (x == -1 || !valid(x, u))
                    break;
                dist[x] = dist[u] + 1;
                que.push(x);
                st.kill(1, 0, n - 1, x);
                last = x;
            }
            // u is max, go left
            last = u;
            while (last > 0) {
                int x = st.goGet(1, 0, n - 1, 0, last - 1, a[last], false, false);
                DEBUG(u, x);
                if (x == -1 || !valid(x, u))
                    break;
                dist[x] = dist[u] + 1;
                que.push(x);
                st.kill(1, 0, n - 1, x);
                last = x;
            }
            // u is min, go right
            last = u;
            while (last + 1 < n) {
                int x = st.goGet(1, 0, n - 1, last + 1, n - 1, a[last], true, true);
                DEBUG(u, x);
                if (x == -1 || !valid(u, x))
                    break;
                dist[x] = dist[u] + 1;
                que.push(x);
                st.kill(1, 0, n - 1, x);
                last = x;
            }
            // u is max, go right
            last = u;
            while (last + 1 < n) {
                int x = st.goGet(1, 0, n - 1, last + 1, n - 1, a[last], false, true);
                DEBUG(u, x);
                if (x == -1 || !valid(u, x))
                    break;
                dist[x] = dist[u] + 1;
                que.push(x);
                st.kill(1, 0, n - 1, x);
                last = x;
            }
            // auto it = st.lower_bound(u);
            // while (it != st.begin() && valid(*prev(it), u)) {
            //     dist[*prev(it)] = dist[u] + 1;
            //     que.push(*prev(it));
            //     it = st.erase(prev(it));
            // }
            // while (it != st.end() && valid(u, *it)) {
            //     dist[*it] = dist[u] + 1;
            //     que.push(*it);
            //     it = st.erase(it);
            // }
        }
        cout << dist[n-1] << "\n";
    }

    return 0;
}