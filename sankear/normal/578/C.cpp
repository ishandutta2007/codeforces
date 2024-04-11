#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash

#ifdef _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 2e4;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(2e5) + 100;
const int ITERS = 100;

int n;
int a[N];

inline double calc(double x) {
    double ans = -1e100, sum = 0, min_sum = 0, max_sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] - x;
        ans = max(ans, fabs(sum - min_sum));
        ans = max(ans, fabs(sum - max_sum));
        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);
    }
    return ans;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //a[i] = -10000 + rand() % 20001;
        scanf("%d", a + i);
    }
    double l = -inf, r = inf, ans = 1e100;
    for (int it = 0; it < ITERS; ++it) {
        double m1 = l + (r - l) / 3;
        double f1 = calc(m1);
        double m2 = r - (r - l) / 3;
        double f2 = calc(m2);
        ans = min(ans, min(f1, f2));
        if (f1 < f2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    printf("%.18lf\n", ans);
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}