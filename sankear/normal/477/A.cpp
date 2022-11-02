#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int MOD = int(1e9) + 7;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    int res = (1LL * a * (a + 1) / 2) % MOD;
    res = (1LL * res * b + a) % MOD;
    int mul = (1LL * b * (b - 1) / 2) % MOD;
    res = (1LL * res * mul) % MOD;
    cout << res << endl;
    return 0;
}