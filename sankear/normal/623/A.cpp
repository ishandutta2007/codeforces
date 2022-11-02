#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 555;

int n;
bool can_b[N];
int col[N];
bool e[N][N];
char s[N];

inline void fail() {
    puts("No");
    exit(0);
}

void dfs(int v, int c) {
    col[v] = c;
    for (int i = 0; i < n; ++i) {
        if (i != v && !e[v][i]) {
            if (col[i] == -1) {
                dfs(i, 1 - c);
            } else if (col[i] != 1 - c) {
                fail();
            }
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        e[a][b] = e[b][a] = true;
    }
    for (int i = 0; i < n; ++i) {
        col[i] = -1;
        can_b[i] = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && !e[i][j]) {
                can_b[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (can_b[i]) {
            s[i] = 'b';
        } else {
            s[i] = (col[i] == 0 ? 'a' : 'c');
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (e[i][j]) {
                    char x = s[i], y = s[j];
                    if (x > y) {
                        swap(x, y);
                    }
                    if (!(x == y || (x == 'a' && y == 'b') || (x == 'b' && y == 'c'))) {
                        fail();
                    }
                } else {
                    char x = s[i], y = s[j];
                    if (x > y) {
                        swap(x, y);
                    }
                    if (!(x == 'a' && y == 'c')) {
                        fail();
                    }
                }
            }
        }
    }
    puts("Yes");
    puts(s);
    return 0;
    
}