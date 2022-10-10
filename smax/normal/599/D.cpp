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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x;
    cin >> x;

    vector<pair<long long, long long>> v;
    for (long long n=1; ; n++) {
        long long m = (6 * x + n * n * n - n) / (3 * n * n + 3 * n);
        if (n > m)
            break;
        if ((6 * x + n * n * n - n) % (3 * n * n + 3 * n) == 0)
            v.emplace_back(n, m);
    }

    int sz = v.size();
    for (int i=sz-1; i>=0; i--)
        if (v[i].first != v[i].second)
            v.emplace_back(v[i].second, v[i].first);

    cout << v.size() << "\n";
    for (auto &p : v)
        cout << p.first << " " << p.second << "\n";

    return 0;
}