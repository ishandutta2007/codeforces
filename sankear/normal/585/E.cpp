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
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(5e5) + 100;
const int M = int(1e7) + 100;
const int MOD = int(1e9) + 7;

int sz;
int a[N], pw[N];
int cnt[M], cnt2[M], p[M], dp[M], primes[M];


inline void init() {
    sz = 0;
    for (int i = 2; i < M; ++i) {
        if (p[i] == 0) {
            p[i] = i;
            primes[sz++] = i;
        }
        for (int j = 0; j < sz && primes[j] <= p[i] && i * primes[j] < M; ++j) {
            p[i * primes[j]] = primes[j];
        }
    }
}

int main() {
    cerr << (sizeof(cnt) + sizeof(cnt2) + sizeof(p)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    for (int i = 2; i < M; ++i) {
        cnt2[i] = 0;
        for (int j = i; j < M; j += i) {
            cnt2[i] += cnt[j];
        }
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = (2LL * pw[i - 1]) % MOD;
    }
    int ans = 0;
    for (int i = M - 1; i >= 2; --i) {
        dp[i] = pw[cnt2[i]] - 1;
        if (dp[i] < 0) {
            dp[i] += MOD;
        }
        for (int j = 2 * i; j < M; j += i) {
            dp[i] -= dp[j];
            if (dp[i] < 0) {
                dp[i] += MOD;
            }
        }
        sz = 0;
        int cur = i;
        while (cur > 1) {
            int del = p[cur];
            while (cur % del == 0) {
                cur /= del;
            }
            primes[sz++] = del;
        }
        int other = 0;
        for (int j = 1; j < (1 << sz); ++j) {
            int val = 1, c = 0;
            for (int z = 0; z < sz; ++z) {
                if ((j & (1 << z)) != 0) {
                    ++c;
                    val *= primes[z];
                }
            }
            if (c % 2 != 0) {
                other += cnt2[val];
            } else {
                other -= cnt2[val];
            }
        }
        other = n - other;
        ans = (ans + 1LL * dp[i] * other) % MOD;
    }
    cout << ans << endl;
    return 0;
}