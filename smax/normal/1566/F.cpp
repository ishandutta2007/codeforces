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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        vector<pair<int, int>> intervals;
        for (int i=0; i<m; i++) {
            int l, r;
            cin >> l >> r;
            intervals.emplace_back(l, r);
        }

        sort(a.begin(), a.end());
        sort(intervals.begin(), intervals.end(), [] (const pair<int, int> &p, const pair<int, int> &q) -> bool {
            if (p.second == q.second)
                return p.first > q.first;
            return p.second < q.second;
        });
        int ptr = 0;
        set<int> st;
        vector<pair<int, int>> ninv;
        for (auto [l, r] : intervals) {
            while (ptr < n && a[ptr] <= r)
                st.insert(a[ptr++]);
            auto it = st.lower_bound(l);
            if (it == st.end()) {
                st.insert(l);
                ninv.emplace_back(l, r);
            }
        }
        intervals = ninv;

        if (intervals.empty()) {
            cout << "0\n";
            continue;
        }

        // dp[i][j] - take j intervals to the right
        // consider taking k intervals to the left
        // find split point where if you take k, k - 1, k - 2, ..., 0 on the left, you pay 2 * cost_to_left + cost_to_right
        // otherwise, you pay cost_to_left + 2 * cost_to_right
        int i = 0;
        vector<long long> pref{max(a[0] - intervals[0].second, 0)}, suff{2LL * max(a[0] - intervals[0].second, 0)};
        while (i < (int) intervals.size() && intervals[i].second < a[0]) {
            pref.push_back(a[0] - intervals[0].second);
            suff.push_back(2LL * (a[0] - intervals[0].second));
            i++;
        }
        vector<long long> dp;
        for (int j=0; j<n; j++) {
            dp.clear();
            int k = i;
            {
                int l = 1, r = (int) pref.size();
                long long costRight = 0;
                while (l < r) {
                    int x = (l + r) / 2;
                    long long costLeft = a[j] - intervals[k-x].second;
                    if (costLeft < costRight)
                        l = x + 1;
                    else
                        r = x;
                }
                l--;
                dp.push_back(min(suff[(int)suff.size()-l-1] + costRight, (l < (int) pref.size() - 1 ? pref[(int)pref.size()-l-2] : (long long) 1e18) + 2 * costRight));
            }
            while (i < (int) intervals.size() && (j == n - 1 || intervals[i].second < a[j+1])) {
                int l = 1, r = (int) pref.size();
                long long costRight = intervals[i].first - a[j];
                while (l < r) {
                    int x = (l + r) / 2;
                    long long costLeft = x > 0 ? a[j] - intervals[k-x].second : 0;
                    if (costLeft < costRight)
                        l = x + 1;
                    else
                        r = x;
                }
                l--;
                dp.push_back(min(suff[(int)suff.size()-l-1] + costRight, (l < (int) pref.size() - 1 ? pref[(int)pref.size()-l-2] : (long long) 1e18) + 2 * costRight));
                i++;
            }
            if (j + 1 < n) {
                pref.resize(dp.size());
                suff.resize(dp.size());
                for (int x=0; x<(int)pref.size(); x++)
                    pref[x] = min(x > 0 ? pref[x-1] : LLONG_MAX, dp[x] + (x < (int) pref.size() - 1 ? a[j+1] - intervals[k+x].second : 0));
                for (int x=(int)suff.size()-1; x>=0; x--)
                    suff[x] = min(x + 1 < (int) suff.size() ? suff[x+1] : LLONG_MAX, dp[x] + 2 * (x < (int) suff.size() - 1 ? a[j+1] - intervals[k+x].second : 0));
            }
        }
        cout << dp.back() << "\n";
    }

    return 0;
}