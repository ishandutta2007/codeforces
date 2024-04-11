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

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 4;
const int primes[] = { 2, 3, 5, 7 };

struct state {
    
    int a, b, c, d;
    
    state(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    
};

int cnt[N];
int del[10][N];
bool used[110][65][20][20];
int len[110][65][20][20];
vector<state> lst, nlst;

int calc(int a, int b, int c, int d) {
    if (used[a][b][c][d]) {
        return len[a][b][c][d];
    }
    used[a][b][c][d] = true;
    int& res = len[a][b][c][d];
    res = -inf;
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        res = 0;
    }
    for (int i = 2; i <= 9; ++i) {
        if (del[i][0] <= a && del[i][1] <= b && del[i][2] <= c && del[i][3] <= d) {
            res = max(res, calc(a - del[i][0], b - del[i][1], c - del[i][2], d - del[i][3]) + 1);
        }
    }
    return res;
}

int main() {
    cerr << (sizeof(used) + sizeof(len)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 2; i < 10; ++i) {
        int cur = 1;
        for (int j = 2; j <= i; ++j) {
            cur *= j;
        }
        for (int j = 0; j < N; ++j) {
            while (cur % primes[j] == 0) {
                ++del[i][j];
                cur /= primes[j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf(" %c", &ch);
        for (int j = 0; j < N; ++j) {
            cnt[j] += del[ch - '0'][j];
        }
    }
    int len = calc(cnt[0], cnt[1], cnt[2], cnt[3]);
    lst.pb(state(cnt[0], cnt[1], cnt[2], cnt[3]));
    for (int i = 0; i < len; ++i) {
        bool good = false;
        for (int j = 9; j > 1; --j) {
            bool found = false;
            for (int z = 0; z < sz(lst); ++z) {
                state cur = lst[z];
                if (cur.a >= del[j][0] && cur.b >= del[j][1] && cur.c >= del[j][2] && cur.d >= del[j][3]) {
                    state ncur(cur.a - del[j][0], cur.b - del[j][1], cur.c - del[j][2], cur.d - del[j][3]);
                    if (calc(ncur.a, ncur.b, ncur.c, ncur.d) + 1 == len - i) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                continue;
            }
            nlst.clear();
            for (int z = 0; z < sz(lst); ++z) {
                state cur = lst[z];
                if (cur.a >= del[j][0] && cur.b >= del[j][1] && cur.c >= del[j][2] && cur.d >= del[j][3]) {
                    state ncur(cur.a - del[j][0], cur.b - del[j][1], cur.c - del[j][2], cur.d - del[j][3]);
                    if (calc(ncur.a, ncur.b, ncur.c, ncur.d) + 1 == len - i) {
                        nlst.pb(ncur);
                    }
                }
            }
            nlst.swap(lst);
            printf("%d", j);
            good = true;
            break;
        }
        assert(good);
    }
    puts("");
    return 0;
}