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
const int N = 3030;

#define left huleft
#define right huright

ll min_right[N], val[N];
ll left[N][N], s[N][N], right[N][N];
int a[N], pos[N];
pii b[N];

int main() {
    cerr << (sizeof(left) + sizeof(right) + sizeof(s)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = mp(a[i] - i, i);
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        pos[b[i].sc] = i;
    }
    for (int i = 0; i < n; ++i) {
        min_right[i] = linf;
        for (int j = 0; j <= i; ++j) {
            right[i][j] = linf;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            s[i][j] = (j < i ? s[i][j + 1] : 0) + abs(a[j] - (a[i] - (i - j)));
        }
    }
    for (int i = 0; i < n; ++i) {
        min_right[i] = linf;
        for (int j = 0; j <= i; ++j) {
            right[i][j] = linf;
            if (j == 0 || a[j - 1] <= a[i] - (i - (j - 1))) {
                right[i][j] = min(right[i][j], s[i][j] + (j > 0 ? min_right[j - 1] : 0));
            }
            if (j > 0 && pos[i] > 0) {
                right[i][j] = min(right[i][j], left[j - 1][pos[i] - 1] + s[i][j]);
            }
            min_right[i] = min(min_right[i], right[i][j]);
        }
        for (int j = 0; j < i; ++j) {
            val[j] += abs(a[i] - (a[j] + (i - j)));
        }
        for (int j = 0; j < n; ++j) {
            left[i][j] = linf;
        }
        for (int j = 0; j <= i; ++j) {
            left[i][pos[j]] = val[j] + min_right[j];
        }
        for (int j = 1; j < n; ++j) {
            left[i][j] = min(left[i][j], left[i][j - 1]);
        }
    }
    ll ans = linf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, min_right[i] + val[i]);
    }
    cout << ans << endl;
    return 0;
}