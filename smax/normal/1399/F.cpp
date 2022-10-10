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

#define MAXN 3005

int l[MAXN], r[MAXN], compression[200005], dp[2*MAXN][2*MAXN];
vector<int> li[2*MAXN], ri[2*MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i=0; i<n; i++) {
            cin >> l[i] >> r[i];
            v.push_back(l[i]);
            v.push_back(r[i]);
        }

        sort(v.begin(), v.end());
        for (int i=0; i<2*n; i++) {
            compression[v[i]] = i + 1;
            li[i+1].clear();
            ri[i+1].clear();
        }

        for (int i=0; i<n; i++) {
            li[compression[l[i]]].push_back(compression[r[i]]);
            ri[compression[r[i]]].push_back(compression[l[i]]);
        }

        for (int i=2*n; i>=0; i--)
            for (int j=i; j<=2*n; j++) {
                dp[i][j] = (i + 1 <= j ? max(dp[i+1][j], dp[i][j-1]) : 0);
                int cnt = 0;
                for (int x : li[i]) {
                    if (x == j)
                        cnt++;
                    else if (x < j)
                        dp[i][j] = max(dp[i][j], dp[i][x] + dp[x+1][j]);
                }
                for (int x : ri[j]) {
                    if (x > i)
                        dp[i][j] = max(dp[i][j], dp[i][x-1] + dp[x][j]);
                }
                dp[i][j] += cnt;
            }

        cout << dp[0][2*n] << "\n";
    }

    return 0;
}