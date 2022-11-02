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
const int N = 30;
const int X = int(2e5) + 3;
const int Y = 4243;

const char names[] = { 'L', 'M', 'W' };

struct tp {
    
    int a, b;
    
};

bool operator == (const tp& a, const tp& b) {
    return a.a == b.a && a.b == b.b;
}

struct hasher {
    
    int operator () (const tp& p) const {
        return (p.a + 1) * X  + (p.b + 1) * Y;
    }
    
};

int n, ans = -inf, mask;
int tmp[3];
int res[N], best_res[N];
int add[N][3][3];
unordered_map<tp, pii, hasher> mem;

void gen1(int x, int y, int a, int b, int c) {
    if (x >= n / 2) {
        tp cur = { a - b, a - c };
        if (mem.find(cur) != mem.end()) {
            mem[cur] = max(mem[cur], mp(a, y));
        } else {
            mem[cur] = mp(a, y);
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        gen1(x + 1, y * 3 + i, a + add[x][i][0], b + add[x][i][1], c + add[x][i][2]);
    }
}

void gen2(int x, int a, int b, int c) {
    if (x >= n) {
        tp cur = { b - a, c - a };
        if (mem.find(cur) != mem.end()) {
            pii val = mem[cur];
            if (val.fs + a > ans) {
                ans = val.fs + a;
                mask = val.sc;
                for (int i = n / 2 - 1; i >= 0; --i) {
                    res[i] = mask % 3;
                    mask /= 3;
                }
                for (int i = 0; i < n; ++i) {
                    best_res[i] = res[i];
                }
            }
        }
        return;
    }
    for (int i = 0; i < 3; ++i) {
        res[x] = i;
        gen2(x + 1, a + add[x][i][0], b + add[x][i][1], c + add[x][i][2]);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", tmp + j);
        }
        for (int j = 0; j < 3; ++j) {
            for (int z = 0; z < 3; ++z) {
                if (j == z) {
                    add[i][j][z] = 0;
                } else {
                    add[i][j][z] = tmp[z];
                }
            }
        }
    }
    gen1(0, 0, 0, 0, 0);
    gen2(n / 2, 0, 0, 0);
    if (ans == -inf) {
        puts("Impossible");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j != best_res[i]) {
                printf("%c", names[j]);
            }
        }
        puts("");
    }
    return 0;
}