#pragma comment(linker, "/STACK:256000000")

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
const int N = 111;

int ans[N][N];
vi nums[2];
vector<pii> pos[2];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int need, n, m;
    cin >> need >> n >> m;
    for (int i = 1; i <= need; ++i) {
        nums[i % 2].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pos[(i + j) % 2].pb(mp(i, j));
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (sz(pos[i]) >= sz(nums[0]) && sz(pos[i ^ 1]) >= sz(nums[1])) {
            for (int num : nums[0]) {
                pii p = pos[i].back();
                pos[i].pbk();
                ans[p.fs][p.sc] = num;
            }
            for (int num : nums[1]) {
                pii p = pos[i ^ 1].back();
                pos[i ^ 1].pbk();
                ans[p.fs][p.sc] = num;
            }
            for (int j = 0; j < n; ++j) {
                for (int z = 0; z < m; ++z) {
                    printf("%d ", ans[j][z]);
                }
                puts("");
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}