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
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<int> pref(n + 1), mnP(n + 1), mxP(n + 1);
        for (int i=1; i<=n; i++) {
            pref[i] = pref[i-1] + (s[i-1] == '+' ? 1 : -1);
            mnP[i] = min(mnP[i-1], pref[i]);
            mxP[i] = max(mxP[i-1], pref[i]);
        }
        vector<int> mnS(n + 2), mxS(n + 2);
        mnS[n+1] = n;
        mxS[n+1] = -n;
        for (int i=n; i>0; i--) {
            mnS[i] = min(mnS[i+1], pref[i]);
            mxS[i] = max(mxS[i+1], pref[i]);
        }

        for (int i=0; i<m; i++) {
            int l, r;
            cin >> l >> r;
            DEBUG(i, l, r, mxP[l-1], mxS[r+1], mnP[l-1], mnS[r+1], pref[r] - pref[l-1])
            cout << max(mxP[l-1], mxS[r+1] - pref[r] + pref[l-1]) - min(mnP[l-1], mnS[r+1] - pref[r] + pref[l-1]) + 1 << "\n";
        }

    }

    return 0;
}