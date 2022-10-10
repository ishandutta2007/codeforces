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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        vector<vector<pair<int, int>>> sorted(2);
        for (int i=0; i<n; i++) {
            cin >> x[i];
            sorted[x[i] % 2].emplace_back(x[i], i);
        }
        vector<char> dir(n);
        for (int i=0; i<n; i++)
            cin >> dir[i];

        auto calc = [&] (int i, int j) -> int {
            assert(x[i] % 2 == x[j] % 2);
            if (dir[i] == 'L') {
                if (dir[j] == 'L') {
                    return x[i] + (x[j] - x[i]) / 2;
                } else {
                    int a = min(x[i], m - x[j]), b = max(x[i], m - x[j]) - a, l = x[i] - a, r = x[j] + a;
                    if (l == 0)
                        l += b;
                    else
                        l -= b;
                    if (r == m)
                        r -= b;
                    else
                        r += b;
                    return a + b + (r - l) / 2;
                }
            } else {
                if (dir[j] == 'L')
                    return (x[j] - x[i]) / 2;
                else
                    return m - x[j] + (x[j] - x[i]) / 2;
            }
        };

        vector<int> ret(n, -1);
        for (int rep=0; rep<2; rep++) {
            sort(sorted[rep].begin(), sorted[rep].end());
            priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
            set<pair<pair<int, int>, int>> st;
            for (int i=0; i<(int)sorted[rep].size(); i++) {
                st.emplace(sorted[rep][i], i);
                if (i > 0) pq.push({calc(sorted[rep][i-1].second, sorted[rep][i].second), i - 1, i});
            }

            while (!pq.empty()) {
                auto [d, i, j] = pq.top();
                pq.pop();
                if (!st.count({sorted[rep][i], i}) || !st.count({sorted[rep][j], j}))
                    continue;
                ret[sorted[rep][i].second] = ret[sorted[rep][j].second] = d;
                st.erase({sorted[rep][i], i});
                st.erase({sorted[rep][j], j});
                auto it1 = st.lower_bound({sorted[rep][i], i}), it2 = st.lower_bound({sorted[rep][j], j});
                if (it1 != st.begin() && it2 != st.end()) {
                    it1 = prev(it1);
                    pq.push({calc(it1->first.second, it2->first.second), it1->second, it2->second});
                }
            }
        }

        for (int d : ret)
            cout << d << " ";
        cout << "\n";
    }

    return 0;
}