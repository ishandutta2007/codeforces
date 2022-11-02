#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e4) + 100;

int p[N], s[N];
ll dp[N], ndp[N];

inline void update(ll& a, ll b) {
    if (b < a) {
        a = b;
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", s + i);
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            ndp[j] = linf;
        }
        for (int j = 0; j <= i; ++j) {
            // take
            update(ndp[j + 1], dp[j] + s[i]);
            // not take
            update(ndp[j], dp[j] + p[i] + 1LL * j * c);
        }
        for (int j = 0; j <= i + 1; ++j) {
            dp[j] = ndp[j];
        }
    }
    ll ans = linf;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}