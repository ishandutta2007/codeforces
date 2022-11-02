#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9 + 100;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(4e5) + 100;

int a[N], b[N], d[N];
vi lst[N];
int del[N];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = n; i < 2 * n; ++i) {
        a[i] = a[i - n];
    }
    for (int s = 1; s < n; ++s) {
        lst[gcd(s, 2 * n)].pb(s);
    }
    ll ans = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if ((2 * n) % i == 0 && sz(lst[i]) > 0) {
            for (int j = 0; j < i; ++j) {
                b[j] = -inf;
                int pos = j;
                for (int z = 0; z < (2 * n) / i; ++z) {
                    b[j] = max(b[j], a[pos]);
                    pos += i;
                    if (pos >= 2 * n) {
                        pos -= 2 * n;
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                del[j] = 0;
            }
            for (int j = 2 * n - 1; j >= 0; --j) {
                d[j] = 0;
                if (a[j] >= b[j % i]) {
                    d[j] = 1 + d[j + 1];
                }
                if (j < n) {
                    ++del[d[j]];
                }
            }
            int ost = n - del[0], ptr = 0;
            for (int j = 1; j < n && ptr < sz(lst[i]) && ost > 0; ++j) {
                if (lst[i][ptr] == j) {
                    ans += ost;
                    ++ptr;
                }
                ost -= del[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}