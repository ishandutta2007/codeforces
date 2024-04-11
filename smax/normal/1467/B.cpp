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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<int> extrema;
        for (int i=1; i<n-1; i++)
            if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]))
                extrema.push_back(i);

        int sub = 1;
        for (int i=1; i<(int)extrema.size(); i++) {
            if (extrema[i-1] + 1 == extrema[i]) {
                int x = extrema[i-1], y = extrema[i];
                if (a[x] > a[x-1] && a[x] > a[x+1]) {
                    if (x == 1 || a[x-1] <= a[x-2] || a[y] >= a[x-1] || y == n - 2 || a[y+1] >= a[y+2] || a[x] <= a[y+1])
                        sub = 2;
                } else {
                    if (x == 1 || a[x-1] >= a[x-2] || a[y] <= a[x-1] || y == n - 2 || a[y+1] <= a[y+2] || a[x] >= a[y+1])
                        sub = 2;
                }
            }
            if (i + 1 < (int) extrema.size() && extrema[i-1] + 1 == extrema[i] && extrema[i] + 1 == extrema[i+1]) {
                sub = 3;
                break;
            }
        }
        cout << max((int) extrema.size() - sub, 0) << "\n";
    }

    return 0;
}