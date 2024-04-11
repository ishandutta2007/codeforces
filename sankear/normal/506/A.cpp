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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int MAGIC = 400;
const int N = int(3e4);

int cnt[N + 10];
int d[N + 1][2 * MAGIC + 1];

int main() {
    //cerr << sizeof(d) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n, D;
    scanf("%d %d", &n, &D);
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        ++cnt[cur];
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = -MAGIC; j <= MAGIC; ++j) {
            d[i][j + MAGIC] = -inf;
        }
    }
    d[D][0 + MAGIC] = cnt[0] + cnt[D];
    for (int i = D; i < N; ++i) {
        for (int j = -MAGIC; j <= MAGIC; ++j) {
            if (d[i][j + MAGIC] == -inf) {
                continue;
            }
            for (int z = -1; z <= 1; ++z) {
                int len = j + D + z;
                if (j + z < -MAGIC || j + z > MAGIC || len < 1 || i + len > N) {
                    continue;
                }
                d[i + len][j + z + MAGIC] = max(d[i + len][j + z + MAGIC], d[i][j + MAGIC] + cnt[i + len]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = -MAGIC; j <= MAGIC; ++j) {
            ans = max(ans, d[i][j + MAGIC]);
        }
    }
    cout << ans << endl;
    return 0;
}