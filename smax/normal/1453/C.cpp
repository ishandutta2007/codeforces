#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i=0; i<n; i++)
            cin >> grid[i];

        vector<int> ret(10);
        for (int rep=0; rep<2; rep++) {
            vector<vector<int>> lastB(n, vector<int>(10, -1));
            for (int i=n-1; i>=0; i--)
                for (int d=0; d<10; d++)
                    if (i + 1 < n) {
                        lastB[i][d] = lastB[i+1][d];
                        for (int j=0; j<n; j++)
                            if (grid[i+1][j] - '0' == d)
                                lastB[i][d] = max(lastB[i][d], i + 1);
                    }
            vector<int> lastT(10, -1);
            for (int i=0; i<n; i++) {
                vector<vector<int>> lastR(n, vector<int>(10, -1));
                for (int j=n-1; j>=0; j--)
                    for (int d=0; d<10; d++)
                        if (j + 1 < n)
                            lastR[j][d] = max(lastR[j+1][d], grid[i][j+1] - '0' == d ? j + 1 : -1);
                vector<int> lastL(10, -1);
                for (int j=0; j<n; j++) {
                    int d = grid[i][j] - '0';
                    // transform something left or right
                    if (lastT[d] != -1)
                        ret[d] = max(ret[d], (i - lastT[d]) * max(j, n - j - 1));
                    if (lastB[i][d] != -1)
                        ret[d] = max(ret[d], (lastB[i][d] - i) * max(j, n - j - 1));
                    // transform something top or bottom
                    if (lastL[d] != -1)
                        ret[d] = max(ret[d], (j - lastL[d]) * max(i, n - i - 1));
                    if (lastR[i][d] != -1)
                        ret[d] = max(ret[d], (lastR[i][d] - j) * max(i, n - i - 1));
                    if (lastL[d] == -1)
                        lastL[d] = j;
                }
                for (int j=0; j<n; j++)
                    if (lastT[grid[i][j]-'0'] == -1)
                        lastT[grid[i][j]-'0'] = i;
            }
            vector<string> nGrid(n, string(n, '0'));
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    nGrid[j][i] = grid[i][j];
            grid = nGrid;
        }
        for (int i=0; i<10; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }

    return 0;
}