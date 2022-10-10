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

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;

        int ret = (mp.empty() ? 0 : (--mp.end())->second) + 20;
        auto it = mp.lower_bound(t - 89);
        ret = min(ret, (it == mp.begin() ? 0 : (--it)->second) + 50);
        it = mp.lower_bound(t - 1439);
        ret = min(ret, (it == mp.begin() ? 0 : (--it)->second) + 120);

        cout << ret - (mp.empty() ? 0 : (--mp.end())->second) << "\n";
        mp[t] = ret;
    }

    return 0;
}