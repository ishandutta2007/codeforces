#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
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
        int n;
        string s;
        cin >> n >> s;

        string t;
        bool canPop = false;
        for (int i=0; i<n; i++) {
            if (s[i] == '0') {
                if (canPop) {
                    while (!t.empty() && t.back() != '2')
                        t.pop_back();
                } else {
                    while (!t.empty() && t.back() == '1') {
                        canPop = true;
                        t.pop_back();
                    }
                    if (!canPop)
                        s[i] = '2';
                }
            }
            t += s[i];
        }
        for (char &c : t)
            if (c == '2')
                c = '0';

        cout << t << "\n";
    }

    return 0;
}