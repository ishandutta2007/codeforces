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

    long long h;
    int n;
    cin >> h >> n;
    pair<long long, int> mn(LLONG_MAX, n);
    vector<long long> d(n), pref(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
        pref[i] = d[i];
        if (i > 0) pref[i] += pref[i-1];
        mn = min(mn, {pref[i], i});
        if (h + pref[i] <= 0) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    if (h + mn.first <= 0) {
        cout << mn.second + 1 << "\n";
        return 0;
    }
    if (pref.back() >= 0) {
        cout << "-1\n";
        return 0;
    }

    long long full = max((mn.first + h - pref.back() - 1) / -pref.back() - 1, 0LL);
    h += pref.back() * full;
    assert(h > 0);
    for (int i=0; i<3*n; i++) {
        h += d[i % n];
        if (h <= 0) {
            cout << full * n + i + 1 << "\n";
            return 0;
        }
    }
    assert(false);

    return 0;
}