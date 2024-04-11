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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }

        vector<int> v;
        for (const auto &p : mp)
            if (p.second >= k)
                v.push_back(p.first);

        int l = 0, r = -1;
        for (int i=0; i<(int)v.size(); ) {
            int j = i + 1;
            while (j < (int) v.size() && v[j-1] + 1 == v[j])
                j++;
            if (v[j-1] - v[i] > r - l) {
                l = v[i];
                r = v[j-1];
            }
            i = j;
        }

        if (l == 0)
            cout << "-1\n";
        else
            cout << l << " " << r << "\n";
    }

    return 0;
}