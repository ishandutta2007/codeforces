#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int a[200000];

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

        long long tot = 0;
        vector<int> b, c;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (i % 2 == 0) {
                tot += a[i];
                if (i > 0)
                    b.push_back(a[i-1] - a[i]); // start at odd index
            } else {
                c.push_back(a[i] - a[i-1]); // start at even index
            }
        }

        long long ret = tot, sum = 0;
        for (int x : b) {
            sum = max(sum, 0LL) + x;
            ret = max(ret, tot + sum);
        }
        sum = 0;
        for (int x : c) {
            sum = max(sum, 0LL) + x;
            ret = max(ret, tot + sum);
        }

        cout << ret << "\n";
    }

    return 0;
}