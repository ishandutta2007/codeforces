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
const int N = int(1e4) + 100;
const int MAGIC = int(1e5);

int a[N][10];
bool used[MAGIC];
int perm[N];

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int ptr = 1, ptr2 = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = ptr;
            ptr += 2;
        }
        a[i][3] = ptr2;
        if (i % 2 == 0) {
            ptr2 += 2;
        } else {
            ptr2 += 4;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans * k << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int z = j + 1; z < 4; ++z) {
                assert(gcd(a[i][j] * k, a[i][z] * k) == k);
            }
        }
        for (int j = 0; j < 4; ++j) {
            printf("%d ", a[i][j] * k);
        }
        puts("");
    }
    return 0;
}