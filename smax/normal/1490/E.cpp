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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());
        vector<long long> pref(n);
        for (int i=0; i<n; i++)
            pref[i] = a[i].first + (i > 0 ? pref[i-1] : 0);

        vector<long long> suff(n);
        for (int i=n-1; i>=0; i--)
            suff[i] = min((i > 0 ? pref[i-1] : 0) - a[i].first, i + 1 < n ? suff[i+1] : LLONG_MAX);

        vector<int> ret;
        for (int i=0; i<n; i++)
            if (i == n - 1 || suff[i+1] >= 0)
                ret.push_back(a[i].second);
        sort(ret.begin(), ret.end());

        cout << ret.size() << "\n";
        for (int i : ret)
            cout << i + 1 << " ";
        cout << "\n";
    }

    return 0;
}