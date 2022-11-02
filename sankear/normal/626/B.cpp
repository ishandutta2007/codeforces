#include <iostream>
#include <unistd.h>
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
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 222;

int r;
char s[N];
bool can[N][N][N];
int q[N * N * N * 3];
int tmp[3];

inline void go() {
    if (!can[tmp[0]][tmp[1]][tmp[2]]) {
        can[tmp[0]][tmp[1]][tmp[2]] = true;
        q[r++] = tmp[0];
        q[r++] = tmp[1];
        q[r++] = tmp[2];
    }
}

void bfs(int x, int y, int z) {
    can[x][y][z] = true;
    int l = 0;
    r = 3;
    q[0] = x;
    q[1] = y;
    q[2] = z;
    while (l < r) {
        tmp[0] = q[l++], tmp[1] = q[l++], tmp[2] = q[l++];
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (tmp[i] > 0 && tmp[j] > 0) {
                    --tmp[i];
                    --tmp[j];
                    ++tmp[3 - i - j];
                    go();
                    --tmp[3 - i - j];
                    ++tmp[i];
                    ++tmp[j];
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (tmp[i] >= 2) {
                --tmp[i];
                go();
                ++tmp[i];
            }
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d %s", &n, s);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++x;
        }
        if (s[i] == 'G') {
            ++y;
        }
        if (s[i] == 'R') {
            ++z;
        }
    }
    bfs(x, y, z);
    if (can[1][0][0]) {
        printf("B");
    }
    if (can[0][1][0]) {
        printf("G");
    }
    if (can[0][0][1]) {
        printf("R");
    }
    puts("");
    return 0;
}