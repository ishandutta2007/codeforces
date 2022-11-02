#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = 22;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
bool can[N][N][4];
bool used[N][N];

void dfs(int x, int y) {
    used[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        if (!can[x][y][i]) {
            continue;
        }
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf(" %c", &ch);
        int cur;
        if (ch == '>') {
            cur = 3;
        } else {
            cur = 1;
        }
        for (int j = 0; j < m; ++j) {
            can[i][j][cur] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        char ch;
        scanf(" %c", &ch);
        int cur;
        if (ch == '^') {
            cur = 0;
        } else {
            cur = 2;
        }
        for (int j = 0; j < n; ++j) {
            can[j][i][cur] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int z = 0; z < n; ++z) {
                for (int h = 0; h < m; ++h) {
                    used[z][h] = false;
                }
            }
            dfs(i, j);
            for (int z = 0; z < n; ++z) {
                for (int h = 0; h < m; ++h) {
                    if (!used[z][h]) {
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
    }
    puts("YES");
    return 0;
}