#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#ifdef _WIN32
#define I64 "%I64d"
#define LLD "%I64d"
#else
#define I64 "%lld"
#define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
    return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
    return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2000;
int x[maxn], v[maxn];

vector<int> l[maxn];

bool main_impl() {
    int n, t;
    if (scanf("%d %d", &n, &t) < 2) return 0;
    for (int i = 0; i <= t; i++) {
        l[i].clear();
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &v[i]);
        l[t - x[i]].pb(v[i]);
    }
    for (int i = t; i > 0; i--) {
        sort(all(l[i]));
        reverse(all(l[i]));
        for (int j = 0; j < sz(l[i]); j++) {
            if (j + 1 < sz(l[i])) {
                l[i - 1].pb(l[i][j] + l[i][j + 1]);
                j++;
            } else {
                l[i - 1].pb(l[i][j]);
            }
        }
        sort(all(l[i - 1]));
        reverse(all(l[i - 1]));
    }
    printf("%d\n", l[0][0]);
    return 1;
}

int main() {
    srand(rdtsc());
    while(main_impl());
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}