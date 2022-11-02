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

vi ans;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vi lst;
    while (n > 0) {
        lst.pb(n % 10);
        n /= 10;
    }
    reverse(all(lst));
    for (;;) {
        int res = 0;
        for (int i = 0; i < sz(lst); ++i) {
            if (lst[i] > 0) {
                --lst[i];
                res = res * 10 + 1;
            } else {
                res = res * 10;
            }
        }
        if (res == 0) {
            break;
        }
        ans.pb(res);
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}