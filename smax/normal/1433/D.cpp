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
        int n;
        cin >> n;
        bool ok = false;
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            if (i > 0) ok |= a[i].first != a[i-1].first;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        sort(a.begin(), a.end());
        vector<pair<int, int>> ret;
        // skip over small, deal with later
        int i = 1;
        while (a[i].first == a[0].first)
            i++;
        int st = i;
        while (i < n) {
            int j = i;
            while (j < n && a[j].first == a[i].first) {
                ret.emplace_back(a[i-1].second, a[j].second);
                j++;
            }
            i = j;
        }
        for (int b=0; b<st-1; b++)
            ret.emplace_back(a[b].second, a[n-1].second);

        assert((int) ret.size() == n - 1);
        cout << "YES\n";
        for (auto &p : ret)
            cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}