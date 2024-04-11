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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), first(n, -1), last(n), tot(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
        if (first[a[i]] == -1)
            first[a[i]] = i;
        last[a[i]] = i;
        tot[a[i]]++;
    }

    vector<int> dp(n + 1), cnt(n);
    for (int i=n-1; i>=0; i--) {
        cnt[a[i]]++;
        // move a_i
        dp[i] = dp[i+1];
        // move everything except color a_i
        // if it's not the first occurrence of a_i, we have to move everything to account for more occurrences of a_i later
        if (i == first[a[i]])
            dp[i] = max(dp[i], dp[last[a[i]] + 1] + tot[a[i]]);
        else
            dp[i] = max(dp[i], cnt[a[i]]);
    }
    cout << n - dp[0] << "\n";

    return 0;
}