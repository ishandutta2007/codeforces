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

        vector<pair<int, int>> a(n), ret;
        for (int i=0; i<n; i++) {
            a[i].first = i + 1;
            a[i].second = i;
        }
        while (a[n-1].first > 2 || a[n-2].first > 1) {
            int i = n - 2;
            while (a[i-1].first > a[n-1].first / a[i-1].first) {
                ret.emplace_back(a[i].second, a[n-1].second);
                a[i].first = (a[i].first + a[n-1].first - 1) / a[n-1].first;
                i--;
            }
            if (a[i].first > 1) {
                ret.emplace_back(a[n-1].second, a[i].second);
                a[n-1].first = (a[n-1].first + a[i].first - 1) / a[i].first;
            }
            sort(a.begin(), a.end());
        }

        assert((int) ret.size() <= n + 5);
        cout << ret.size() << "\n";
        for (auto &p : ret)
            cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}