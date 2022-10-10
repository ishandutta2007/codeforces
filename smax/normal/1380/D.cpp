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

int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    long long x, k, y;
    cin >> n >> m >> x >> k >> y;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];

    long long ret = 0;
    for (int i=0, j=0, l=0; j<=m; l=b[j], i++, j++) {
        int mx = 0, len = 0;
        while (i <= n && a[i] != b[j]) {
            mx = max(mx, a[i++]);
            len++;
        }
        if (i > n) {
            cout << "-1\n";
            return 0;
        }
        if (len == 0)
            continue;
        if (mx < l || mx < a[i]) {
            if (k * y < x)
                ret += y * len;
            else
                ret += x * (len / k) + y * (len % k);
        } else {
            if (len < k) {
                cout << "-1\n";
                return 0;
            }
            if (k * y < x)
                ret += x + y * (len - k);
            else
                ret += x * (len / k) + y * (len % k);
        }
    }
    cout << ret << "\n";

    return 0;
}