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

int dr[] = {-2, 0, 1, 2, 0, -1};
int dc[] = {0, 2, 1, 0, -2, -1};

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int n, a[50][50];

void dfs(int r, int c) {
    for (int d=0; d<6; d++)
        if (0 <= r + dr[d] && r + dr[d] < n && 0 <= c + dc[d] && c + dc[d] < n && a[r+dr[d]][c+dc[d]] == -1) {
            a[r+dr[d]][c+dc[d]] = query(min(r, r + dr[d]), min(c, c + dc[d]), max(r, r + dr[d]), max(c, c + dc[d])) ^ a[r][c] ^ 1;
            dfs(r + dr[d], c + dc[d]);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;

    memset(a, -1, sizeof(a));
    a[0][0] = 1;
    a[n-1][n-1] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if ((i + j) % 2 == 0)
                for (int d=0; d<3; d++)
                    if (i + d < n && j + 2 - d < n && a[i+d][j+2-d] == -1)
                        a[i+d][j+2-d] = query(i, j, i + d, j + 2 - d) ^ a[i][j] ^ 1;

    for (int i=2; i<n; i++)
        if (a[i][i] != a[i-2][i-2]) {
            if (query(i-2, i-1, i-1, i) == (a[i-2][i-2] == a[i-1][i-1]))
                a[i-2][i-1] = query(i-2, i-2, i-1, i) ^ a[i-1][i-1] ^ 1;
            else
                a[i-2][i-1] = query(i-2, i-1, i, i) ^ a[i][i] ^ 1;
            dfs(i - 2, i - 1);
            break;
        }

    cout << "!\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << a[i][j];
        cout << "\n";
    }

    return 0;
}