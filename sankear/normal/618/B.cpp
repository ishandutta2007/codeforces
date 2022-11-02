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
#include <complex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash
#define link hulink
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 55;

int c[N], d[N], ans[N];
int a[N][N], b[N][N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
        c[i] = i;
    }
    int sz = n;
    for (int i = 1; i <= n; ++i) {
        if (sz == 2) {
            ans[c[0]] = i;
            ans[c[1]] = i + 1;
            break;
        }
        int ind = -1;
        for (int j = 0; j < sz; ++j) {
            bool good = true;
            for (int z = 0; z < sz; ++z) {
                if (j != z && a[j][z] != i) {
                    good = false;
                    break;
                }
            }
            if (good) {
                assert(ind == -1);
                ind = j;
            }
        }
        assert(ind != -1);
        ans[c[ind]] = i;
        for (int j = 0; j < sz; ++j) {
            if (j != ind) {
                assert(a[j][ind] == i);
            }
        }
        int x = 0;
        for (int j = 0; j < sz; ++j) {
            if (j == ind) {
                continue;
            }
            d[x] = c[j];
            int y = 0;
            for (int z = 0; z < sz; ++z) {
                if (z == ind) {
                    continue;
                }
                b[x][y++] = a[j][z];
            }
            ++x;
        }
        --sz;
        for (int j = 0; j < sz; ++j) {
            c[j] = d[j];
            for (int z = 0; z < sz; ++z) {
                a[j][z] = b[j][z];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}