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

long long a[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> a[i][j];

        long long ret = 0;
        for (int i=0; i<n/2; i++)
            for (int j=0; j<m/2; j++) {
                vector<long long> v{a[i][j], a[n-i-1][j], a[i][m-j-1], a[n-i-1][m-j-1]};
                sort(v.begin(), v.end());
                ret += (v[1] - v[0]) + (v[2] - v[1]) + (v[3] - v[1]);
            }
        if (n % 2) {
            for (int j=0; j<m/2; j++)
                ret += abs(a[n/2][j] - a[n/2][m-j-1]);
        }
        if (m % 2) {
            for (int i=0; i<n/2; i++)
                ret += abs(a[i][m/2] - a[n-i-1][m/2]);
        }
        cout << ret << "\n";
    }

    return 0;
}