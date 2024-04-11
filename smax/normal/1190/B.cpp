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

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int mx = 0, cnt = 0, zero = false, huh = -1;
    for (auto &p : mp) {
        mx = max(mx, p.second);
        cnt += p.second == 2;
        if (p.first == 0 && p.second == 2)
            zero = true;
        if (p.second == 2)
            huh = p.first;
    }
    if (mx >= 3 || cnt > 1 || zero || (huh != -1 && mp[huh - 1])) {
        cout << "cslnb\n";
        return 0;
    }
    int ret = 0;
    for (int i=0; i<n; i++)
        ret ^= (a[i] + i) % 2;
    cout << (ret ? "sjfnb" : "cslnb") << "\n";

    return 0;
}