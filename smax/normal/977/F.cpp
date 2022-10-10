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

    int n;
    cin >> n;
    vector<int> dp(n), par(n, -1);
    map<int, int> last;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        dp[i] = 1;
        if (last.count(a - 1)) {
            dp[i] += dp[last[a - 1]];
            par[i] = last[a - 1];
        }
        last[a] = i;
    }

    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ret;
    while (idx != -1) {
        ret.push_back(idx);
        idx = par[idx];
    }
    reverse(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}