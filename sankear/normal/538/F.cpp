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
#include <stack>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
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
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;
const int MAGIC = 500;

int a[N], add[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        //a[i] = rand();
    }
    for (int i = 1; i < n; ++i) {
        int val = 1, next = 2;
        while (val < min(n, MAGIC)) {
            while (next < n && (i - 1) / next == (i - 1) / val) {
                ++next;
            }
            if (a[(i - 1) / val] > a[i]) {
                ++add[val];
                --add[next];
            }
            val = next;
        }
        if (val < n) {
            int cur = (i - 1) / val;
            for (int k = cur; k >= 0; --k) {
                int l, r;
                if (k == 0) {
                    r = n - 1;
                    l = i;
                } else {
                    r = (i - 1) / k;
                    l = (i - 1) / (k + 1) + 1;
                }
                if (l <= r && a[i] < a[k]) {
                    ++add[l];
                    --add[r + 1];
                }
            }
        }
    }
    int cur = 0;
    for (int i = 1; i < n; ++i) {
        cur += add[i];
        printf("%d ", cur);
    }
    puts("");
    return 0;
}