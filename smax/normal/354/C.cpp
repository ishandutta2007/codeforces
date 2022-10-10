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

const int MAX = 1e6 + 5;

int pref[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        pref[a]++;
    }

    for (int i=1; i<MAX; i++)
        pref[i] += pref[i-1];

    int ret = 1;
    for (int i=2; i<MAX; i++) {
        int cur = 0, reach = 0;
        for (int j=i; j<MAX; j+=i) {
            int l = max(j, reach), r = min(j + k, MAX - 1);
            if (l <= r) {
                cur += pref[r] - pref[l-1];
                reach = r + 1;
            }
        }
        if (cur == n)
            ret = max(ret, i);
    }
    cout << ret << "\n";

    return 0;
}