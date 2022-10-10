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

    int l, r;
    cin >> l >> r;

    vector<tuple<int, int, int>> ret;
    r -= l - 1;
    int k = __lg(r);
    for (int j=0; j<=k; j++)
        ret.emplace_back(1, j + 2, 1);
    for (int i=0; i<=k; i++)
        for (int j=i+1; j<=k; j++)
            ret.emplace_back(i + 2, j + 2, 1 << i);
    if ((r & -r) != r) {
        ret.emplace_back(1, k + 3, 1);
        for (int i=0; i<=k; i++)
            if ((r - 1) & (1 << i))
                ret.emplace_back(i + 2, k + 3, 1 + ((r - 1) >> (i + 1) << (i + 1)));
        k++;
    }
    if (l > 1) {
        ret.emplace_back(k + 2, k + 3, l - 1);
        k++;
    }

    cout << "YES\n" << k + 2 << " " << ret.size() << "\n";
    for (auto [a, b, c] : ret)
        cout << a << " " << b << " " << c << "\n";

    return 0;
}