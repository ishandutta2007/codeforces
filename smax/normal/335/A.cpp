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

    string s;
    int n;
    cin >> s >> n;

    vector<int> cnt(26);
    for (char c : s)
        cnt[c-'a']++;

    int diff = 0;
    for (int x : cnt)
        if (x > 0)
            diff++;

    if (diff > n) {
        cout << "-1\n";
        return 0;
    }

    int l = 1, r = (int) s.size() + 1;
    while (l < r) {
        int m = (l + r) / 2, need = 0;
        for (int x : cnt)
            need += (x + m - 1) / m;
        if (need <= n)
            r = m;
        else
            l = m + 1;
    }

    cout << l << "\n";
    string ret(n, 'a');
    int ptr = 0;
    for (int i=0; i<26; i++)
        for (int j=0; j<(cnt[i]+l-1)/l; j++)
            ret[ptr++] = char('a' + i);
    cout << ret << "\n";

    return 0;
}