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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i=0; i<n; i++)
            cin >> w[i];

        int ret = 0;
        vector<int> cnt(n + 1);
        for (int i=0; i<n; i++)
            cnt[w[i]]++;
        for (int s=1; s<=2*n; s++) {
            int cur = 0;
            for (int i=1; i<=n; i++) {
                if (i > s || s - i < i || s - i > n)
                    continue;
                if (i == s - i)
                    cur += cnt[i] / 2;
                else
                    cur += min(cnt[i], cnt[s-i]);
            }
//            DEBUG(s, cur)
            ret = max(ret, cur);
        }

        cout << ret << "\n";
    }

    return 0;
}