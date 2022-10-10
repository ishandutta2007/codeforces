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
        for (int i=0; i<n; i++)
            cin >> a[i];

        // Case 1: Start positive
        int len1 = 0, cur = INT_MIN;
        long long sum1 = 0;
        bool pos = true, first = true;
        for (int i=0; i<n; i++) {
            if ((a[i] > 0) == pos) {
                cur = max(cur, a[i]);
                first = false;
            } else if (!first) {
                len1++;
                sum1 += cur;
                DEBUG(cur)
                pos = !pos;
                cur = a[i];
            }
        }
        len1++;
        sum1 += cur;
        DEBUG(cur)

        DEBUG("BREAK---------")

        // Case 2: Start negative
        int len2 = 0;
        long long sum2 = 0;
        cur = INT_MIN;
        pos = false;
        first = true;
        for (int i=0; i<n; i++) {
            if ((a[i] > 0) == pos) {
                cur = max(cur, a[i]);
                first = false;
            } else if (!first) {
                len2++;
                sum2 += cur;
                DEBUG(cur)
                pos = !pos;
                cur = a[i];
            }
        }
        len2++;
        sum2 += cur;
        DEBUG(cur)
        DEBUG(len1, sum1, len2, sum2)

        if (len1 > len2)
            cout << sum1 << "\n";
        else if (len1 < len2)
            cout << sum2 << "\n";
        else
            cout << max(sum1, sum2) << "\n";
    }

    return 0;
}