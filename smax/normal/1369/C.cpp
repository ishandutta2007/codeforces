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

int a[200000], w[200000];

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
        for (int i=0; i<k; i++)
            cin >> w[i];

        sort(a, a + n);
        sort(w, w + k, [] (int x, int y) {
            if (x != 1 && y != 1)
                return x > y;
            return (x == 1) > (y == 1);
        });
        long long ret = 0;
        for (int i=0, j=0; i<k; i++) {
            int l = j;
            for (; j<l+w[i]-1; j++);
            DEBUG(j)
            ret += a[n-i-1] + (w[i] == 1 ? a[n-i-1] : a[l]);
        }

        cout << ret << "\n";
    }

    return 0;
}