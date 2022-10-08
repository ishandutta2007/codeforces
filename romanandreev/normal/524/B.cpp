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
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

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

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())


const int maxn = 1000;
const int maxh = 1000;

int w[maxn], h[maxn];

bool solve() {
    int n;
    if (scanf("%d", &n) != 1) {
        return false;
    }
    int mw = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &h[i]);
        if (w[i] > h[i]) {
            swap(w[i], h[i]);
        }
        mw = max(mw, w[i]);
    }

    int ans = (int) 2e9;

    for (int i = mw; i <= maxh; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (h[j] <= i) {
                if (w[j] < h[j]) {
                    swap(w[j], h[j]);
                }
            }
            sum += h[j];
        }
        ans = min(ans, sum * i);
    }
    printf("%d\n", ans);

    return true;
}

int main() {
    srand(rdtsc());
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (1) {
      if (!solve())
        break;
#ifdef DEBUG
//      eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
    return 0;
}