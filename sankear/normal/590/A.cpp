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
const int N = int(5e5) + 100;

int a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (i == n - 1) {
            break;
        }
        if (a[i + 1] == a[i]) {
            ++i;
            continue;
        }
        int j = i + 1;
        while (j + 1 < n && a[j + 1] != a[j]) {
            ++j;
        }
        int l = i + 1, r = j - 1, cur = 0;
        while (l <= r) {
            a[l++] = a[i];
            a[r--] = a[j];
            ++cur;
        }
        ans = max(ans, cur);
        i = j;
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}