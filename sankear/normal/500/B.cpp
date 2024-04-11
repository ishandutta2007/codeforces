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
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32 || _WIN64
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
const int N = 333;

int n;
int a[N];
char can[N][N];
vi lst, vals;
bool used[N];

void dfs(int v) {
    used[v] = true;
    lst.pb(v);
    vals.pb(a[v]);
    for (int i = 0; i < n; ++i) {
        if (can[v][i] == '1' && !used[i]) {
            dfs(i);
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    gets(can[0]);
    for (int i = 0; i < n; ++i) {
        gets(can[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            lst.clear();
            vals.clear();
            dfs(i);
            sort(all(lst));
            sort(all(vals));
            for (int j = 0; j < sz(lst); ++j) {
                a[lst[j]] = vals[j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}