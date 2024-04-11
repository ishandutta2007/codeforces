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

int a[5005];

int solve(int l, int r) {
    int mn = *min_element(a + l, a + r + 1), pred = -1, ret = mn;
    for (int i=l; i<=r; i++) {
        a[i] -= mn;
        if (a[i] == 0) {
            if (pred != -1)
                ret += solve(pred, i - 1);
            pred = -1;
        } else if (pred == -1) {
            pred = i;
        }
    }
    if (pred != -1 && a[r] != 0)
        ret += solve(pred, r);
    return min(ret, r - l + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    cout << solve(0, n - 1) << "\n";

    return 0;
}