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
const int MOD = int(1e9) + 7;
const int N = 2020;

char s[N], t[N];
int next[N][30];
int go[N], cnt[N];
int last[30];
int d[N][N];
int ans[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%s %s", s, t);
    int n = (int) strlen(s), m = (int) strlen(t);
    for (int i = 0; i < 26; ++i) {
        last[i] = -1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            next[i][j] = last[j];
        }
        last[s[i] - 'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0]) {
            int pos = i, sum = 0;
            for (int j = 1; j < m; ++j) {
                sum += next[pos][t[j] - 'a'] - pos - 1;
                pos = next[pos][t[j] - 'a'];
                if (pos == -1) {
                    break;
                }
            }
            go[i] = pos;
            cnt[i] = sum;
        } else {
            go[i] = -1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            d[i][j] = inf;
        }
    }
    d[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (d[i][j] == inf) {
                continue;
            }
            d[i + 1][j] = min(d[i + 1][j], d[i][j]);
            if (go[i] != -1) {
                d[go[i] + 1][j + 1] = min(d[go[i] + 1][j + 1], d[i][j] + cnt[i]);
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (d[n][i] == inf) {
            continue;
        }
        for (int j = d[n][i]; j <= n - i * m; ++j) {
            ans[j] = max(ans[j], i);
        }
    }
    for (int i = 0; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}