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

const int INF = 1e9 + 5;

int c[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> c[i];

    int l = 1, r = 2 * INF;
    while (l < r) {
        int m = l + (r - l) / 2;
        DEBUG(l, r, m)
        long long cost = 0;
        for (int i=0; i<n; i++)
            cost += max(m - c[i], 0);

        if (cost <= k)
            l = m + 1;
        else
            r = m;
    }
    DEBUG(l - 1)
    int kk = k;
    for (int i=0; i<n; i++) {
        int change = min(kk, max(l - 1 - c[i], 0));
        c[i] += change;
        kk -= change;
    }
    for (int i=0; i<n && kk>0; i++)
        if (c[i] == l - 1) {
            c[i]++;
            kk--;
        }

    l = 1, r = 2 * INF;
    while (l < r) {
        int m = l + (r - l) / 2;
        long long cost = 0;
        for (int i=0; i<n; i++)
            cost += max(c[i] - m, 0);

        if (cost <= k)
            r = m;
        else
            l = m + 1;
    }
    DEBUG(l)
    for (int i=0; i<n; i++) {
        int change = min(k, max(c[i] - l, 0));
        c[i] -= change;
        k -= change;
    }
    for (int i=0; i<n && k>0; i++)
        if (c[i] == l) {
            c[i]--;
            k--;
        }

    cout << *max_element(c, c + n) - *min_element(c, c + n) << "\n";

    return 0;
}