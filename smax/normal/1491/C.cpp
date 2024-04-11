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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i=0; i<n; i++)
            cin >> s[i];

        long long ret = 0;
        vector<long long> dp(n), suff(n);
        for (int i=n-1; i>=0; i--) {
            int change = max(s[i] - max(n - i - 1, 1), 0);
            ret += change;
            dp[i] += change;
            s[i] -= change;
            DEBUG("NEW", i, change);
            assert(s[i] == 1 || i + s[i] < n);
            int take = 0;
            vector<int> stk;
            for (int j=n-1; j>i+s[i]; j--)
                if (dp[j] > 0)
                    stk.push_back(j);
            while (s[i] > 1) {
                dp[i]++;
                if (dp[i + s[i]] > 0)
                    stk.push_back(i + s[i]);
                if (!stk.empty()) {
                    DEBUG("PIGGY", i, i + s[i]);
                    if (--dp[stk.back()] == 0)
                        stk.pop_back();
                    take++;
                } else {
                    DEBUG("NEW", i, s[i]);
                    ret++;
                }
                s[i]--;
            }
            for (int j=n-1; j>=i; j--)
                suff[j] = dp[j] + (j + 1 < n ? suff[j+1] : 0);
            DEBUG(suff);
        }
        cout << ret << "\n";
    }

    return 0;
}