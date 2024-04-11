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

int n, cnt = 0;

inline void myassert(bool fl) {
    if (!fl) {
        cerr << "FUCK" << endl;
        while (1);
    }
}

inline int ask(int x1, int y1, int x2, int y2) {
    ++cnt;
    myassert(1 <= x1 && x1 <= x2 && x2 <= n);
    myassert(1 <= y1 && y1 <= y2 && y2 <= n);
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

inline pair<pii, pii> solve(int x1, int y1, int x2, int y2) {
    myassert(1 <= x1 && x1 <= x2 && x2 <= n);
    myassert(1 <= y1 && y1 <= y2 && y2 <= n);
    int up = x1, down = x2, left = y1, right = y2;
    int l = x1 + 1, r = x2;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(mid, y1, x2, y2) == 1) {
            up = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = x1, r = x2 - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(x1, y1, mid, y2) == 1) {
            down = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    l = y1 + 1, r = y2;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(x1, mid, x2, y2) == 1) {
            left = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = y1, r = y2 - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(x1, y1, x2, mid) == 1) {
            right = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    myassert(ask(up, left, down, right) == 1);
    return mp(mp(up, left), mp(down, right));
}

inline void print(pair<pii, pii> a, pair<pii, pii> b) {
    myassert(cnt <= 200);
    cout << "! " << a.fs.fs << " " << a.fs.sc << " " << a.sc.fs << " " << a.sc.sc << " ";
    cout << b.fs.fs << " " << b.fs.sc << " " << b.sc.fs << " " << b.sc.sc << endl;
    exit(0);
}

int main() {
    cin >> n;
    int x2 = -1, l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(1, 1, mid, n) > 0) {
            x2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    myassert(x2 != -1);
    if (ask(1, 1, x2, n) == 1 && ask(x2 + 1, 1, n, n) == 1) {
        print(solve(1, 1, x2, n), solve(x2 + 1, 1, n, n));
    }
    int y2 = -1;
    l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ask(1, 1, n, mid) > 0) {
            y2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    myassert(y2 != -1 && ask(1, 1, n, y2) == 1);
    myassert(ask(1, y2 + 1, n, n) == 1);
    print(solve(1, 1, n, y2), solve(1, y2 + 1, n, n));
    return 0;
}