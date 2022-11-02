#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define pbk pop_back
#define prev _prev
#define rank _rank
#define next _next
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const double inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 2020;
const int M = int(2e5) + 100;
const int MOD = int(1e9) + 7;

pii a[N];
int good[N];
int f[M], rf[M];

inline int calc_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

inline int cnk(int n, int k) {
    assert(k >= 0 && k <= n);
    int res = (1LL * f[n] * rf[k]) % MOD;
    res = (1LL * res * rf[n - k]) % MOD;
    return res;
}

inline int calc(int n, int m) {
    return cnk(n + m - 2, n - 1);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].fs, &a[i].sc);
    }
    a[n++] = mp(1, 1);
    f[0] = 1;
    for (int i = 1; i <= 2 * max(h, w) + 10; ++i) {
        f[i] = (1LL * f[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= 2 * max(h, w) + 10; ++i) {
        rf[i] = calc_pow(f[i], MOD - 2);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) {
        good[i] = calc(h - a[i].fs + 1, w - a[i].sc + 1);
        for (int j = i + 1; j < n; ++j) {
            if (a[j].fs >= a[i].fs && a[j].sc >= a[i].sc) {
                ll bad = (1LL * calc(a[j].fs - a[i].fs + 1, a[j].sc - a[i].sc + 1) * good[j]) % MOD;
                good[i] -= bad;
                if (good[i] < 0) {
                    good[i] += MOD;
                }
            }
        }
    }
    cout << good[0] << endl;
    return 0;
}