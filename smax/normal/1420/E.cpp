#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAXN = 85;
const int INF = 1e9;

int dp[MAXN][MAXN][MAXN*(MAXN-1)/2], ndp[MAXN][MAXN][MAXN*(MAXN-1)/2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> pos;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == 1) pos.push_back(i);
    }

    for (int ops=0; ops<=n*(n-1)/2; ops++)
        dp[0][0][ops] = -INF;
    dp[0][0][0] = 0;

    // position, which 1, last 1, number of operations
    for (int i=0; i<n; i++) {
        for (int j=0; j<=min(i,(int)pos.size())+1; j++)
            for (int last=0; last<=i+1; last++)
                for (int ops=0; ops<=n*(n-1)/2; ops++)
                    ndp[j][last][ops] = -INF;
        for (int j=0; j<=min(i,(int)pos.size()); j++)
            for (int last=0; last<=i; last++)
                for (int ops=0; ops<=n*(n-1)/2; ops++) {
                    // place a 0
                    ndp[j][last][ops] = max(ndp[j][last][ops], dp[j][last][ops]);
                    // place a 1
                    if (j < (int) pos.size() && n - (int) pos.size() - i + j >= 0 && ops + abs(i - pos[j]) <= n * (n - 1) / 2)
                        ndp[j+1][i+1][ops+abs(i-pos[j])] = max(ndp[j+1][i+1][ops+abs(i-pos[j])], dp[j][last][ops] + (n - (int) pos.size() - i + j) * (i - last));
                }
        for (int j=0; j<=min(i,(int)pos.size())+1; j++)
            for (int last=0; last<=i+1; last++)
                for (int ops=0; ops<=n*(n-1)/2; ops++)
                    dp[j][last][ops] = ndp[j][last][ops];
    }

    int ret = 0;
    for (int ops=0; ops<=n*(n-1)/2; ops++) {
        for (int j=0; j<=(int)pos.size(); j++)
            for (int last=0; last<=n; last++)
                ret = max(ret, dp[j][last][ops]);
        cout << ret << " ";
    }
    cout << "\n";

    return 0;
}