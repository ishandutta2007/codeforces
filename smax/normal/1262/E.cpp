#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

string grid[1000000];
vector<vector<int>> pref;

int query(int r1, int c1, int r2, int c2) {
    int ret = pref[r2][c2];
    if (r1 > 0) ret -= pref[r1-1][c2];
    if (c1 > 0) ret -= pref[r2][c1-1];
    if (r1 > 0 && c1 > 0) ret += pref[r1-1][c1-1];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> grid[i];

    pref.resize(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            pref[i][j] = (grid[i][j] == 'X');
            if (i > 0) pref[i][j] += pref[i-1][j];
            if (j > 0) pref[i][j] += pref[i][j-1];
            if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }

    int l = 0, r = min(n, m);
    vector<pair<int, int>> ret;
    while (l < r) {
        int mid = (l + r) / 2, sz = 2 * mid + 1;
        vector<pair<int, int>> cur;
        vector<vector<int>> curGrid(n, vector<int>(m));
        for (int i=0; i<=n-sz; i++)
            for (int j=0; j<=m-sz; j++) {
                if (query(i, j, i + sz - 1, j + sz - 1) == sz * sz) {
                    cur.emplace_back(i + sz / 2, j + sz / 2);
                    curGrid[i][j]++;
                    if (i + sz < n) curGrid[i+sz][j]--;
                    if (j + sz < m) curGrid[i][j+sz]--;
                    if (i + sz < n && j + sz < m) curGrid[i+sz][j+sz]++;
                }
            }

        bool ok = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (i > 0) curGrid[i][j] += curGrid[i-1][j];
                if (j > 0) curGrid[i][j] += curGrid[i][j-1];
                if (i > 0 && j > 0) curGrid[i][j] -= curGrid[i-1][j-1];
                if ((curGrid[i][j] > 0) != (grid[i][j] == 'X')) {
                    ok = false;
                    break;
                }
            }

        if (ok) {
            l = mid + 1;
            ret = cur;
        } else {
            r = mid;
        }
    }

    vector<string> out(n, string(m, '.'));
    for (auto p : ret)
        out[p.first][p.second] = 'X';

    cout << l - 1 << "\n";
    for (string s : out)
        cout << s << "\n";

    return 0;
}