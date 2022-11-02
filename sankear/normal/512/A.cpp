#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 111;

int sz;
int used[N];
int lst[N];
int len[N];
char s[N][N];
vi g[N];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        } else if (used[g[v][i]] == 1) {
            puts("Impossible");
            exit(0);
        }
    }
    used[v] = 2;
    lst[sz++] = v;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        len[i] = (int) strlen(s[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int ptr = 0;
        while (ptr < len[i] && ptr < len[i + 1] && s[i][ptr] == s[i + 1][ptr]) {
            ++ptr;
        }
        if (ptr < len[i] && ptr < len[i + 1]) {
            g[s[i][ptr] - 'a'].pb(s[i + 1][ptr] - 'a');
        } else {
            if (len[i] > len[i + 1]) {
                puts("Impossible");
                return 0;
            }
        }
    }
    sz = 0;
    for (int i = 0; i < 26; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 25; i >= 0; --i) {
        printf("%c", 'a' + lst[i]);
    }
    return 0;
}