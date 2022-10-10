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

    int n, m;
    cin >> n >> m;
    vector<int> vert;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        vert.push_back(x);
    }
    sort(vert.begin(), vert.end());
    vert.push_back(1000000000);

    int blockHori = 0;
    vector<pair<int, int>> hori;
    for (int i=0; i<m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1 && x2 >= vert[0]) {
            blockHori++;
            hori.emplace_back(x2, y);
        }
    }
    sort(hori.begin(), hori.end());
    int ret = blockHori;
    for (int i=0, j=0; i<n; i++) {
        while (j < (int) hori.size() && hori[j].first < vert[i+1]) {
            blockHori--;
            j++;
        }
        ret = min(ret, blockHori + i + 1);
    }
    cout << ret << "\n";

    return 0;
}