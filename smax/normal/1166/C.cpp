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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    auto query0 = [&] (int x) {
        return (int) (upper_bound(a.begin(), a.end(), x) - a.begin());
    };

    auto query = [&] (int x, int y) {
        if (x > y) return 0;
        return query0(y) - query0(x - 1);
    };

    sort(a.begin(), a.end());
    long long ret = 0;
    for (int i=0; i<n; i++) {
        if (a[i] >= 0)
            ret += query((a[i] + 1) / 2, a[i] - 1) + query(-a[i], min(-(a[i] + 1) / 2, -1)) + query(-2 * a[i], -a[i] - 1);
        else
            ret += query(2 * a[i], a[i] - 1);
    }
    cout << ret << "\n";

    return 0;
}