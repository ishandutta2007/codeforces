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
        vector<int> a(n), diff, possible;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (i > 0)
                diff.push_back(abs(a[i] - a[i-1]));
            if (i >= 2)
                possible.push_back(abs(a[i] - a[i-1]) + abs(a[i-1] - a[i-2]) - abs(a[i] - a[i-2]));
        }
        possible.push_back(abs(a[1] - a[0]));
        possible.push_back(abs(a[n-1] - a[n-2]));
        sort(possible.begin(), possible.end());
        cout << accumulate(diff.begin(), diff.end(), 0LL) - possible.back() << "\n";
    }

    return 0;
}