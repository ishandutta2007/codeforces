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
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
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
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 4040;

int n;
bool used[N];
int v[N], d[N], p[N];
vi ans;

void go(int v) {
    used[v] = true;
    for (int i = v + 1; i < n; ++i) {
        p[i] -= d[v];
        if (!used[i] && p[i] < 0) {
            go(i);
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", v + i, d + i, p + i);
    }
    for (;;) {
        int old_size = sz(ans);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ans.pb(i);
                used[i] = true;
                int cur = v[i];
                for (int j = i + 1; j < n && cur > 0; ++j) {
                    if (!used[j]) {
                        p[j] -= cur--;
                    }
                }
                for (int j = i + 1; j < n; ++j) {
                    if (!used[j] && p[j] < 0) {
                        go(j);
                    }
                }
            }
        }
        if (old_size == sz(ans)) {
            break;
        }
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
    return 0;
}