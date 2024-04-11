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

    vector<long long> pw(10);
    pw[0] = 1;
    for (int i=1; i<10; i++)
        pw[i] = pw[i-1] * 10;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        auto getMax = [&] (auto &self, int i, long long k) -> long long {
            if (i < 0)
                return 0;
            // figure out maximum amount attainable by this prefix, see if it reaches the next threshold
            long long target = pw[a[i]] - 1, used = 0;
            for (int j=i-1; j>=0; j--) {
                used += target / pw[a[j]];
                target %= pw[a[j]];
            }
            assert(used <= k);
            // use one more than permitted, see what the gap is
            long long cur = min(k - used + 1, (long long) k) * pw[a[i]], leftOver = k - min(k - used + 1, k);
            // see what the previous can make at maximum
            return cur + self(self, i - 1, leftOver);
        };

        for (int i=0; i<n; i++) {
            long long cur = getMax(getMax, i, k);
            if (i == n - 1 || cur < pw[a[i+1]] - 1) {
                cout << cur + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}