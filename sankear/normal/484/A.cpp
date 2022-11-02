#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define next _next
#ifdef LOCAL42
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

inline void solve() {
    ll l, r;
    scanf(LLD " " LLD, &l, &r);
    pair<int, ll> ans = max(mp(__builtin_popcountll(l), -l), mp(__builtin_popcountll(r), -r));
    for (int i = 1; i <= 60; ++i) {
        ll cur = (l | ((1LL << i) - 1));
        if (cur >= l && cur <= r) {
            ans = max(ans, mp(__builtin_popcountll(cur), -cur));
        }
    }
    printf(LLD "\n", -ans.sc);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}