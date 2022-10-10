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
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool ok = true;
        vector<char> v(k, '?');
        for (int i=0; i<n; i++) {
            if (s[i] != '?' && v[i%k] != '?' && s[i] != v[i%k]) {
                ok = false;
                break;
            }
            if (v[i%k] == '?')
                v[i%k] = s[i];
        }
        int zero = 0, one = 0;
        for (int i=0; i<k; i++) {
            if (v[i] == '0') zero++;
            else if (v[i] == '1') one++;
        }
        if (one > k / 2 || zero > k / 2)
            ok = false;
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}