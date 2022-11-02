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
#define all(s) (s).begin(), (s).end()
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
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
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int n;
int a[N], cnt[N];

inline bool inside(int l, int r, int x) {
    return l <= x && x <= r;
}

inline bool good(int l, int r) {
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < (n + 1) / 2; ++i) {
        int ri = n - i - 1;
        if (inside(l, r, i) && inside(l, r, ri)) {
            ++cnt[a[i]];
            if (i != ri) {
                ++cnt[a[ri]];
            }
            continue;
        }
        if (inside(l, r, i)) {
            ++cnt[a[i]];
            --cnt[a[ri]];
            continue;
        }
        if (inside(l, r, ri)) {
            --cnt[a[i]];
            ++cnt[a[ri]];
            continue;
        }
        if (a[i] != a[ri]) {
            return false;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] < 0) {
            return false;
        }
        sum += cnt[i] % 2;
    }
    return sum < 2;
}

inline ll solve_even() {
    int board = 0, l = 0, r = n - 1;
    while (l < r && a[l++] == a[r--]) {
        ++board;
    }
    ll ans = 0;
    if (board == n / 2) {
        return 1LL * n * (n + 1) / 2;
    } else {
        int middle = 0;
        while (n / 2 + middle < n && a[n / 2 - middle - 1] == a[n / 2 + middle]) {
            ++middle;
        }
        int l = n / 2 + middle, r = n - 1 - board;
        assert(l <= r);
        if (good(l, r)) {
            ans += 2LL * (l - n / 2 + 1) * (n - r);
        }
    }
    int res = -1;
    l = n / 2, r = n - 1 - board;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(board, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (res != -1) {
        ans += 1LL * (board + 1) * (n - res);
    }
    res = -1;
    l = board;
    r = n / 2 - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(mid, n - 1 - board)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (res != -1) {
        ans += 1LL * (board + 1) * (res + 1);
        ans -= 1LL * (board + 1) * (board + 1);
    }
    return ans;
}

inline ll solve_odd() {
    int board = 0, l = 0, r = n - 1;
    while (l <= r && a[l++] == a[r--]) {
        ++board;
    }
    ll ans = 0;
    if (board == n / 2 + 1) {
        return 1LL * n * (n + 1) / 2;
    } else {
        int middle = 1;
        while (n / 2 + middle < n && a[n / 2 - middle] == a[n / 2 + middle]) {
            ++middle;
        }
        int l = n / 2 + middle, r = n - 1 - board;
        assert(l <= r);
        if (good(l, r)) {
            ans += 2LL * (l - n / 2) * (n - r);
        }
    }
    int res = -1;
    l = n / 2, r = n - 1 - board;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(board, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (res != -1) {
        ans += 1LL * (board + 1) * (n - res);
    }
    res = -1;
    l = board;
    r = n / 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(mid, n - 1 - board)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (res != -1) {
        ans += 1LL * (board + 1) * (res + 1);
        ans -= 1LL * (board + 1) * (board + 1);
    }
    return ans;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    if (n % 2 == 0) {
        cout << solve_even() << endl;
    } else {
        cout << solve_odd() << endl;
    }
    return 0;
}