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

const int MAXN = 32;

int hori[MAXN][MAXN], vert[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i=0; i<MAXN; i++) {
        int ptr = 1;
        hori[i][0] = 1;
        for (int j=1; j<5; j++) {
            auto it = copy(hori[i], hori[i] + ptr, hori[i] + ptr + 1);
            hori[i][ptr] = 1 << (2 * j);
            ptr = int(it - hori[i]);
        }
    }
    for (int i=0; i<MAXN; i++) {
        int ptr = 1;
        vert[0][i] = 2;
        for (int j=1; j<5; j++) {
            for (int k=0; k<ptr; k++)
                vert[k+ptr+1][i] = vert[k][i];
            vert[ptr][i] = 1 << (2 * j + 1);
            ptr = 2 * ptr + 1;
        }
    }

    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++)
        for (int j=0; j<n-1; j++)
            cout << hori[i][j] << " \n"[j==n-2];
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n; j++)
            cout << vert[i][j] << " \n"[j==n-1];
    cout.flush();

    vector val(n, vector<int>(n));
    vector<pair<int, int>> ret(1024);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            if (i > 0) val[i][j] = val[i-1][j] ^ vert[i-1][j];
            else if (j > 0) val[i][j] = val[i][j-1] ^ hori[i][j-1];
            ret[val[i][j]] = {i, j};
        }

    int tot = 0;
    for (int i=0; i<k; i++) {
        int x;
        cin >> x;
        tot ^= x;
        cout << ret[tot].first + 1 << " " << ret[tot].second + 1 << endl;
    }

    return 0;
}