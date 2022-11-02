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
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define LLD "%I64d"
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

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    for (int i = 0; i < sz(s); ++i) {
        int cur = s[i] - '0', inv = 9 - cur;
        if (i == 0 && inv == 0) {
            continue;
        }
        if (inv < cur) {
            s[i] = '0' + inv;
        }
    }
    ll ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans = ans * 10 + s[i] - '0';
    }
    cout << ans << endl;
    return 0;
}