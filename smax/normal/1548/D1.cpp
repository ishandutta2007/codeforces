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

    int n;
    cin >> n;
    vector<vector<int>> cnt(2, vector<int>(2));
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x % 4 / 2][y % 4 / 2]++;
    }

    long long ret = 0;
    for (int a=0; a<2; a++)
        for (int b=0; b<2; b++)
            for (int c=0; c<2; c++)
                for (int d=0; d<2; d++)
                    for (int e=0; e<2; e++)
                        for (int f=0; f<2; f++) {
                            int bound = (a != c || b != d) + (a != e || b != f) + (c != e || d != f);
                            if (bound == 0 || bound == 2) {
                                if (a == c && b == d && a == e && b == f)
                                    ret += (long long) cnt[a][b] * (cnt[a][b] - 1) * (cnt[a][b] - 2);
                                else if (a == c && b == d)
                                    ret += (long long) cnt[a][b] * (cnt[a][b] - 1) * cnt[e][f];
                                else if (a == e && b == f)
                                    ret += (long long) cnt[a][b] * (cnt[a][b] - 1) * cnt[c][d];
                                else if (c == e && d == f)
                                    ret += (long long) cnt[a][b] * cnt[c][d] * (cnt[c][d] - 1);
                                else
                                    ret += (long long) cnt[a][b] * cnt[c][d] * cnt[e][f];
                            }
                        }
    cout << ret / 6 << "\n";

    return 0;
}