#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define next _next
#ifdef LOCAL42
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9) + 100;
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e6) + 100;
const int LOG = 20;

int n;
char s[N], ns[N];
int p[LOG][N];

inline void move(int k, int d) {
    int ptr = 0;
    for (int i = 0; i < d; ++i) {
        for (int j = i; j < k; j += d) {
            p[0][j] = ptr++;
        }
    }
    for (int i = k; i < n; ++i) {
        p[0][i] = i;
    }
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[i - 1][j] < (1 << (i - 1))) {
                p[i][j] = p[i - 1][j];
            } else {
                p[i][j] = p[i - 1][p[i - 1][j] - (1 << (i - 1))] + (1 << (i - 1));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int need = n - k + 1, cur = i, add = 0;
        for (int j = LOG - 1; j >= 0; --j) {
            if (need >= (1 << j)) {
                if (cur >= add) {
                    cur = p[j][cur - add] + add;
                }
                add += (1 << j);
                need -= (1 << j);
            }
        }
        ns[cur] = s[i];
    }
    for (int i = 0; i < n; ++i) {
        s[i] = ns[i];
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gets(s);
    n = (int) strlen(s);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int k, d;
        scanf("%d %d", &k, &d);
        move(k, d);
        puts(s);
    }
    return 0;
}