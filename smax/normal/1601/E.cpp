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
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (i++; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }

    void update(int i, T val) {
        for (i++; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    vector<vector<pair<int, int>>> queries(n);
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[l].emplace_back(r, i);
    }

    vector<int> nd(k, -1);
    for (int i=0; i<n+k; i++)
        if (i + k - 1 >= n && nd[i % k] == -1)
            nd[i % k] = i / k;

    RMQ rmq(a);
    vector<vector<pair<int, int>>> stk(k);
    vector<long long> ret(q);
    vector<BIT<long long>> bit(k, BIT<long long>((n + k - 1) / k));

    auto getMinPos = [&] (int l, int r, int x) -> int {
        int s = l;
        r++;
        while (l < r) {
            int m = (l + r) / 2;
            if (rmq.query(s, m) == x)
                l = m + 1;
            else
                r = m;
        }
        return l;
    };

    for (int l=n-1; l>=0; l--) {
        if (l + k - 1 < n) {
            int mn = rmq.query(l, l + k - 1), idx = l % k;
            while (!stk[idx].empty() && mn <= stk[idx].back().second) {
                auto [i, x] = stk[idx].back();
                stk[idx].pop_back();
                long long amt = (long long) x * ((stk[idx].empty() ? nd[idx] : stk[idx].back().first) - i);
                bit[idx].update(i, -amt);
            }
            int i = (l - idx) / k;
            long long amt = (long long) mn * ((stk[idx].empty() ? nd[idx] : stk[idx].back().first) - i);
            stk[idx].emplace_back(i, mn);
            bit[idx].update(i, amt);
        }
        int idx = (l + 1) % k;
        for (auto [r, i] : queries[l]) {
            int f = getMinPos(l, r, a[l]);
            ret[i] = a[l];
            int pos = int(lower_bound(stk[idx].begin(), stk[idx].end(), make_pair((r + 1 - idx) / k, INT_MAX), greater<pair<int, int>>()) - stk[idx].begin());
            if (pos != (int) stk[idx].size())
                ret[i] += (long long) max((f - idx) / k - (l + 1 - idx) / k, 0) * a[l] + max(bit[idx].query((f - idx) / k, stk[idx][pos].first - 1), 0LL) + (long long) stk[idx][pos].second * ((r + 1 - idx) / k - max(stk[idx][pos].first, (f - idx) / k));
        }
    }

    for (long long x : ret)
        cout << x << "\n";

    return 0;
}