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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const int N = int(1e5) + 100;

int deg[N], q[N], u[N], v[N];
vi g[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", u + i, v + i);
        --u[i];
        --v[i];
    }
    int ans = -1, l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        for (int i = 0; i < n; ++i) {
            deg[i] = 0;
            g[i].clear();
        }
        for (int i = 0; i < mid; ++i) {
            g[u[i]].pb(v[i]);
            ++deg[v[i]];
        }
        int ql = 0, qr = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                q[qr++] = i;
            }
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            if (qr - ql != 1) {
                good = false;
                break;
            }
            int v = q[ql++];
            for (int u : g[v]) {
                if (--deg[u] == 0) {
                    q[qr++] = u;
                }
            }
        }
        if (good) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}