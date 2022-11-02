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

const int dx[4] = { 1, 1, -1, -1 };
const int dy[4] = { 1, -1, -1, 1 };

int n, m;
map<tuple<int, int, int>, ll> mapx;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k;
    cin >> n >> m >> k;
    int x = 0, y = 0, dir = 0;
    ll t = 0;
    for (;;) {
        mapx[mt(x, y, dir)] = t;
        if (dir == 0) {
            int can = min(n - x, m - y);
            int nx = x + can, ny = y + can;
            x = nx;
            y = ny;
            t += can;
            if (x == n && y == m) {
                break;
            }
            if (x == n) {
                dir = 3;
            } else {
                dir = 1;
            }
            if (mapx.find(mt(x, y, dir)) != mapx.end()) {
                break;
            }
        } else if (dir == 1) {
            int can = min(n - x, y);
            int nx = x + can, ny = y - can;
            x = nx;
            y = ny;
            t += can;
            if (x == n && y == 0) {
                break;
            }
            if (x == n) {
                dir = 2;
            } else {
                dir = 0;
            }
            if (mapx.find(mt(x, y, dir)) != mapx.end()) {
                break;
            }
        } else if (dir == 2) {
            int can = min(x, y);
            int nx = x - can, ny = y - can;
            x = nx;
            y = ny;
            t += can;
            if (x == 0 && y == 0) {
                break;
            }
            if (x == 0) {
                dir = 1;
            } else {
                dir = 3;
            }
            if (mapx.find(mt(x, y, dir)) != mapx.end()) {
                break;
            }
        } else {
            assert(dir == 3);
            int can = min(x, m - y);
            int nx = x - can, ny = y + can;
            x = nx;
            y = ny;
            t += can;
            if (x == 0 && y == m) {
                break;
            }
            if (x == 0) {
                dir = 0;
            } else {
                dir = 2;
            }
            if (mapx.find(mt(x, y, dir)) != mapx.end()) {
                break;
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        ll res = linf;
        int can = min(x, y);
        int nx = x - can, ny = y - can;
        if (mapx.find(mt(nx, ny, 0)) != mapx.end()) {
            res = min(res, mapx[mt(nx, ny, 0)] + can);
        }
        can = min(x, m - y);
        nx = x - can, ny = y + can;
        if (mapx.find(mt(nx, ny, 1)) != mapx.end()) {
            res = min(res, mapx[mt(nx, ny, 1)] + can);
        }
        can = min(n - x, m - y);
        nx = x + can, ny = y + can;
        if (mapx.find(mt(nx, ny, 2)) != mapx.end()) {
            res = min(res, mapx[mt(nx, ny, 2)] + can);
        }
        can = min(n - x, y);
        nx = x + can, ny = y - can;
        if (mapx.find(mt(nx, ny, 3)) != mapx.end()) {
            res = min(res, mapx[mt(nx, ny, 3)] + can);
        }
        if (res == linf) {
            res = -1;
        }
        printf("%lld\n", res);
    }
    return 0;
}