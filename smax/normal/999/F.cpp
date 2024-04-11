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

const int MAX = 1e5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> cnt(MAX), fcnt(MAX), h(k);
    for (int i=0; i<n*k; i++) {
        int c;
        cin >> c;
        cnt[--c]++;
    }
    for (int i=0; i<n; i++) {
        int f;
        cin >> f;
        fcnt[--f]++;
    }
    for (int i=0; i<k; i++)
        cin >> h[i];

    long long ret = 0;
    for (int x=0; x<MAX; x++)
        if (fcnt[x] > 0) {
            vector<long long> dp(cnt[x] + 1);
            for (int rep=0; rep<fcnt[x]; rep++)
                for (int j=cnt[x]; j>=0; j--)
                    for (int l=1; l<=k && j+l<=cnt[x]; l++)
                        dp[j+l] = max(dp[j+l], dp[j] + h[l-1]);
            ret += dp[cnt[x]];
        }
    cout << ret << "\n";

    return 0;
}