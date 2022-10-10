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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        set<int> mergePts;
        for (int i=0; i<n; i++)
            if (a[i] != a[(i+1)%n])
                mergePts.insert(i);

        int ret = 0;
        DEBUG(a, mergePts);
        while (!mergePts.empty()) {
            ret++;
            vector<pair<int, int>> upd;
            for (int i : mergePts)
                upd.emplace_back(i, __gcd(a[i], a[(i+1)%n]));
            mergePts.clear();
            for (auto [i, v] : upd)
                a[i] = v;
            for (auto [i, v] : upd) {
                if (a[(i+n-1)%n] != a[i])
                    mergePts.insert((i + n - 1) % n);
                if (a[i] != a[(i+1)%n])
                    mergePts.insert(i);
            }
            DEBUG(a, mergePts);
        }
        cout << ret << "\n";

        // set<array<int, 4>> st;
        // for (int i=0; i<n; ) {
        //     int j = i;
        //     while (j < n && a[i] == a[j])
        //         j++;
        //     st.insert({i, j - i, a[i], 0});
        //     i = j;
        // }
        // if (st.size() >= 2 && (*st.begin())[2] == (*st.rbegin())[2]) {
        //     auto interval = *st.begin();
        //     interval[0] = (*st.rbegin())[0];
        //     interval[1] += n - interval[0];
        //     st.erase(st.begin());
        //     st.erase(prev(st.end()));
        //     st.insert(interval);
        // }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for (auto it=next(st.begin()); it!=st.end(); it++)
        //     pq.emplace((*prev(it))[1], (*it)[0]);
        // if (st.size() >= 2)
        //     pq.emplace((*st.rbegin())[1], (*st.begin())[0]);

        // auto getInterval = [&] (int i) -> array<int, 4> {
        //     return *st.lower_bound({i, 0, 0, 0});
        // };

        // auto getBefore = [&] (int i) -> array<int, 4> {
        //     auto it = st.lower_bound({i, 0, 0, 0});
        //     assert(it != st.end());
        //     if (it == st.begin())
        //         return *st.rbegin();
        //     return *prev(it);
        // };

        // auto getAfter = [&] (int i) -> array<int, 4> {
        //     auto it = st.lower_bound({i, 0, 0, 0});
        //     assert(it != st.end());
        //     if (next(it) == st.end())
        //         return *st.begin();
        //     return *next(it);
        // };

        // // start, size, value, insertion time
        // DEBUG(a);
        // int curT = 0;
        // while (st.size() > 1) {
        //     DEBUG(pq.size(), st);
        //     int ti = pq.top().first;
        //     set<array<int, 4>> add, rem;
        //     while (!pq.empty() && ti == pq.top().first) {
        //         auto x = getBefore(pq.top().second), y = getInterval(pq.top().second), z = getAfter(pq.top().second);
        //         pq.pop();
        //         rem.insert(x);
        //         rem.insert(y);
        //         if (__gcd(x[2], y[2]) != y[2]) {
        //             x[2] = __gcd(x[2], y[2]);
        //             y[1] -= ti - z[3];
        //             x[3] = y[3] = ti;
        //             add.insert(x);
        //             if (y[1] > 0)
        //                 add.insert(y);
        //         } else {
        //             add.insert({x[0], x[1] + y[1] - (ti - z[3]), __gcd(x[2], y[2]), ti});
        //         }
        //     }
        //     DEBUG(pq.size(), add, rem);
        //     curT = ti;
        //     for (const auto &interval : rem)
        //         st.erase(interval);
        //     for (const auto &interval : add)
        //         st.insert(interval);
        //     for (const auto &interval : add) {
        //         auto it = st.find(interval);
        //         if (it == st.end())
        //             continue;
        //         int sz = 0;
        //         while (true) {
        //             auto nxt = getAfter(interval[0]);
        //             if (nxt == interval || nxt[2] != interval[2])
        //                 break;
        //             sz += nxt[1];
        //             st.erase(nxt);
        //         }
        //         st.erase(interval);
        //         auto newInterval = interval;
        //         newInterval[1] += sz;
        //         st.insert(newInterval);
        //         auto nxt = getAfter(newInterval[0]);
        //         if (nxt != newInterval)
        //             pq.emplace(ti + newInterval[1], nxt[0]);
        //     }
        // }
        // cout << curT << "\n";
    }

    return 0;
}