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

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    if (a - b < 0) {
        puts("-1");
        return 0;
    }
    int k = (a - b) / (2 * b);
    double x = 1e100;
    if (k > 0 && a - b > 0) {
        x = min(x, (a - b) / (2.0 * k));
    }
    x = min(x, (a + b) / (2.0 * (k + 1)));
    printf("%.18lf\n", x);
    return 0;
}