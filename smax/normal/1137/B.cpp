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

int lps[500005];

void preprocess(const string &p) {
    lps[0] = 0;
    int j = 0, m = p.size();
    for (int i=1; i<m; i++) {
        while (j != 0 && p[i] != p[j])
            j = lps[j-1];
        lps[i] = (j += (p[i] == p[j]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    int m = t.size();

    preprocess(t);
    vector<int> cnt(2);
    for (char c : s)
        cnt[c-'0']++;

    int i = 0;
    while (i < m) {
        if (cnt[t[i]-'0'] == 0) {
            cout << string(cnt[0], '0') << string(cnt[1], '1');
            break;
        }
        cout << t[i];
        cnt[t[i++]-'0']--;
        if (i == m)
            i = lps[i-1];
    }
    cout << "\n";

    return 0;
}