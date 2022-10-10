#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ok = true;
        map<long long, int> mp;
        for (int i=0; i<2*n; i++) {
            long long d;
            cin >> d;
            ok &= d % 2 == 0;
            mp[d]++;
        }

        vector<long long> v;
        for (auto &p : mp) {
            ok &= p.second == 2;
            v.push_back(p.first);
        }

        sort(v.begin(), v.end());
        int mul = 2;
        long long sum = 0;
        for (int i=1; i<n; i++) {
            ok &= (v[i] - v[i-1]) % mul == 0;
            sum += 2 * n * (v[i] - v[i-1]) / mul;
            mul += 2;
        }
        ok &= sum < v[n-1] && (v[n-1] - sum) % (2 * n) == 0;

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}