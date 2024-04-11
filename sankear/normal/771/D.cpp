#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 80;

vi a[3];
int dp[N][N][N][3];

inline int get_col(char ch) {
    if (ch == 'V') {
        return 0;
    }
    if (ch == 'K') {
        return 1;
    }
    return 2;
}

inline void update(int& a, int b) {
    if (b < a) {
        a = b;
    }
}

string s;
bool used[N];

inline int dist(int x, int y, int z, int cur) {
    for (int i = 0; i < sz(s); ++i) {
        used[i] = false;
    }
    for (int i = 0; i < sz(s); ++i) {
        if (get_col(s[i]) == 0 && x > 0) {
            used[i] = true;
            --x;
        }
        if (get_col(s[i]) == 1 && y > 0) {
            used[i] = true;
            --y;
        }
        if (get_col(s[i]) == 2 && z > 0) {
            used[i] = true;
            --z;
        }
    }
    int ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (used[i]) {
            continue;
        }
        if (get_col(s[i]) == cur) {
            return ans;
        }
        ++ans;
    }
    assert(false);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[get_col(s[i])].pb(i);
    }
    for (int i = 0; i <= sz(a[0]); ++i) {
        for (int j = 0; j <= sz(a[1]); ++j) {
            for (int z = 0; z <= sz(a[2]); ++z) {
                for (int last = 0; last < 3; ++last) {
                    dp[i][j][z][last] = inf;
                }
            }
        }
    }
    if (sz(a[0]) > 0) {
        dp[1][0][0][0] = a[0][0];
    }
    if (sz(a[1]) > 0) {
        dp[0][1][0][1] = a[1][0];
    }
    if (sz(a[2]) > 0) {
        dp[0][0][1][2] = a[2][0];
    }
    for (int i = 0; i <= sz(a[0]); ++i) {
        for (int j = 0; j <= sz(a[1]); ++j) {
            for (int z = 0; z <= sz(a[2]); ++z) {
                for (int last = 0; last < 3; ++last) {
                    if (dp[i][j][z][last] == inf) {
                        continue;
                    }
                    if (i + 1 <= sz(a[0])) {
                        update(dp[i + 1][j][z][0], dp[i][j][z][last] + dist(i, j, z, 0));
                    }
                    if (j + 1 <= sz(a[1]) && last != 0) {
                        update(dp[i][j + 1][z][1], dp[i][j][z][last] + dist(i, j, z, 1));
                    }
                    if (z + 1 <= sz(a[2])) {
                        update(dp[i][j][z + 1][2], dp[i][j][z][last] + dist(i, j, z, 2));
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int last = 0; last < 3; ++last) {
        update(ans, dp[sz(a[0])][sz(a[1])][sz(a[2])][last]);
    }
    cout << ans << endl;
    return 0;
}