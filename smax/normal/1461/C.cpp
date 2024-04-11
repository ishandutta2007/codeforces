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
    cout << fixed << setprecision(10);
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<pair<int, double>> ops(m);
        for (int i=0; i<m; i++) {
            cin >> ops[i].first >> ops[i].second;
            ops[i].first--;
        }

        sort(ops.rbegin(), ops.rend());
        double ret = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && a[i] == i)
            i--;
        if (i == -1) {
            cout << 1.0 << "\n";
            continue;
        }
        while (j < m && ops[j].first >= i) {
            ret = (1 - ops[j].second) * ret + ops[j].second;
            j++;
        }
        cout << ret << "\n";
    }

    return 0;
}