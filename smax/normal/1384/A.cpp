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
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<string> s(n + 1);
        if (a[0] == 0) {
            s[0] = "a";
            s[1] = "b";
        } else {
            s[0] = s[1] = string(a[0], 'a');
        }
        for (int i=1; i<n; i++) {
            if (a[i] == 0) {
                s[i+1] = s[i][0] == 'a' ? "b" : "a";
                continue;
            }
            if ((int) s[i].size() < a[i]) {
                s[i] += s[i-1].size() > s[i].size() && s[i-1][s[i].size()] == 'a' ? 'b' : 'a';
                s[i] += string(a[i] - (int) s[i].size(), 'a');
            }
            s[i+1] = s[i].substr(0, a[i]);
        }

        for (int i=0; i<=n; i++)
            cout << s[i] << "\n";
    }

    return 0;
}