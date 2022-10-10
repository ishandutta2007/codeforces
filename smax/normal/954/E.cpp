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

    int n, T;
    cin >> n >> T;
    vector<int> a(n), t(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    long double ret = 0;
    vector<pair<int, int>> pos, neg;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        t[i] -= T;
        if (t[i] > 0) pos.emplace_back(t[i], a[i]);
        else if (t[i] < 0) neg.emplace_back(-t[i], a[i]);
        else ret += a[i];
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    long long cur = 0;
    for (auto &p : pos)
        cur += (long long) p.first * p.second;
    long long k = cur;
    cur = 0;
    for (auto &p : neg)
        cur += (long long) p.first * p.second;
    k = min(k, cur);

    long long memo = k;
    for (auto &p : pos) {
        long double need = min((long double) p.second, (long double) k / p.first);
        ret += need;
        k -= need * p.first;
    }
    k = memo;
    for (auto &p : neg) {
        long double need = min((long double) p.second, (long double) k / p.first);
        ret += need;
        k -= need * p.first;
    }
    cout << fixed << setprecision(10) << ret << "\n";

    return 0;
}