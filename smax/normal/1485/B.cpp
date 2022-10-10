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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 1);
    for (int i=1; i<=n; i++)
        cin >> a[i];

    vector<long long> pref(n + 1);
    for (int i=2; i<n; i++)
        pref[i] = pref[i-1] + a[i+1] - a[i-1] - 2;

    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << k - 1 << "\n";
        else
            cout << pref[r-1] - pref[l] + a[l+1] + k - a[r-1] - 3 << "\n";
    }

    return 0;
}