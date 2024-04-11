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
        int n, m = 3, k = 2;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        if (m == 1) {
            cout << n << "\n";
            continue;
        }

        vector<long long> pref(n + 1);
        for (int i=0; i<=n; i++)
            pref[i] = i + (i > 0 ? pref[i-1] : 0);

        long long ret = 0;
        sort(a.begin(), a.end());
        for (int i=0, j=0; i<n; i++) {
            while (j < i && a[i] - a[j] > k)
                j++;
            if (j < i)
                ret += pref[i-j-1];
        }
        cout << ret << "\n";
    }

    return 0;
}