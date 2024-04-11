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

    int n, r;
    long long k;
    cin >> n >> r >> k;
    vector<int> a(n);
    vector<long long> pref(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pref[max(i - r, 0)] += a[i];
        if (i + r + 1 < n) pref[i + r + 1] -= a[i];
    }

    for (int i=1; i<n; i++)
        pref[i] += pref[i-1];

    long long lo = 0, hi = 2e18;
    while (lo < hi) {
        long long mid = (lo + hi) / 2, has = k;
        vector<long long> pref2(n);
        for (int i=0; i<n; i++) {
            if (i > 0) pref2[i] += pref2[i-1];
            long long need = max(mid - (pref[i] + pref2[i]), 0LL);
            pref2[i] += need;
            if (i + 2 * r + 1 < n) pref2[i + 2 * r + 1] -= need;
            has -= need;
            if (has < 0)
                break;
        }
        if (has < 0)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo - 1 << "\n";

    return 0;
}