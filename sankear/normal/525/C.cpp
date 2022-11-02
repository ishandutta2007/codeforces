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
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int a[N], b[N];
set<int> exists;

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
    sort(a, a + n);
    reverse(a, a + n);
    int i = 0, m = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && a[i] == a[j + 1]) {
            ++j;
        }
        int z = i;
        if (exists.find(a[i] + 1) != exists.end()) {
            exists.erase(a[i] + 1);
            b[m++] = a[i];
            ++z;
        }
        if ((j - z + 1) % 2 != 0) {
            exists.insert(a[i]);
            ++z;
        }
        while (z + 1 <= j) {
            b[m++] = a[i];
            z += 2;
        }
        i = j + 1;
    }
    ll ans = 0;
    for (int i = 0; i + 1 < m; i += 2) {
        ans += 1LL * b[i] * b[i + 1];
    }
    cout << ans << endl;
    return 0;
}