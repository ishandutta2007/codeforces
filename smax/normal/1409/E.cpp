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

int x[200005], y[200005], pref[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> x[i];
        for (int i=0; i<n; i++)
            cin >> y[i];

        sort(x, x + n);
        for (int i=0, j=0; j<n; j++) {
            while (i < n && x[j] - x[i] > k)
                i++;
            pref[j] = max(j > 0 ? pref[j-1] : 0, j - i + 1);
        }
        int ret = 0;
        for (int i=n-1, j=n-1; i>=0; i--) {
            while (j >= 0 && x[j] - x[i] > k)
                j--;
            ret = max(ret, j - i + 1 + (i > 0 ? pref[i-1] : 0));
        }
        cout << ret << "\n";
    }

    return 0;
}