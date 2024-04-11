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
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 111;

int a[N][N], b[N][N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            bool good = true;
            for (int z = 0; z < n && good; ++z) {
                for (int h = 0; h < m; ++h) {
                    if (h == i) {
                        b[z][h] = a[z][j];
                    } else if (h == j) {
                        b[z][h] = a[z][i];
                    } else {
                        b[z][h] = a[z][h];
                    }
                }
                bool found = false;
                for (int h = 0; h < m && !found; ++h) {
                    for (int t = h; t < m; ++t) {
                        swap(b[z][h], b[z][t]);
                        bool fl = true;
                        for (int x = 0; x < m; ++x) {
                            if (b[z][x] != x + 1) {
                                fl = false;
                                break;
                            }
                        }
                        if (fl) {
                            found = true;
                            break;
                        }
                        swap(b[z][h], b[z][t]);
                    }
                }
                if (!found) {
                    good = false;
                    break;
                }
            }
            if (good) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}