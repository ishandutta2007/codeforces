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
#ifdef _WIN32
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
const int N = 111;

char a[N][N];
bool eq[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    gets(a[0]);
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        eq[i] = true;
    }
    for (int i = 0; i < m; ++i) {
        bool del = false;
        for (int j = 0; j + 1 < n; ++j) {
            if (!eq[j]) {
                continue;
            }
            if (a[j][i] > a[j + 1][i]) {
                del = true;
                break;
            }
        }
        if (del) {
            ++ans;
            continue;
        }
        for (int j = 0; j + 1 < n; ++j) {
            if (!eq[j]) {
                continue;
            }
            if (a[j][i] < a[j + 1][i]) {
                eq[j] = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}