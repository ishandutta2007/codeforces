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
bool isMountain[200000];

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
            cin >> a[i];

        int ret = 0, cnt = 0;
        for (int i=0; i<n; i++)
            isMountain[i] = (i > 0 && i < n - 1 && a[i] > a[i-1] && a[i] > a[i+1]);
        for (int i=1; i<k-1; i++)
            cnt += isMountain[i];
        ret = cnt;
        int l = 0;

        for (int i=k; i<n; i++) {
            cnt -= isMountain[i-(k-1)];
            cnt += isMountain[i-1];
            if (cnt > ret) {
                ret = cnt;
                l = i - k + 1;
            }
        }

        cout << ret + 1 << " " << l + 1 << "\n";
    }

    return 0;
}