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

    string s;
    int k;
    cin >> s >> k;

    vector<pair<int, int>> cnt(26);
    for (int i=0; i<26; i++)
        cnt[i].second = i;
    for (char c : s)
        cnt[c-'a'].first++;

    sort(cnt.begin(), cnt.end());
    vector<bool> rem(26);
    int m = 26;
    for (auto [x, c] : cnt) {
        if (x > k)
            break;
        k -= x;
        m--;
        rem[c] = true;
    }

    cout << m << "\n";
    for (char c : s)
        if (!rem[c-'a'])
            cout << c;
    cout << "\n";

    return 0;
}