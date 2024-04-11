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
#include <numeric>

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

const int maxn = (int)4e5;
int p[maxn], a[maxn];
vector<int> c[maxn];

pair<ll, ll> go(int v) {
    vector<pair<ll, ll> > ans;
    for (int i = 0; i < sz(c[v]); i++) {
        ans.pb(go(c[v][i]));
    }
    pair<ll, ll> res;
    ll d[2], nd[2];
    d[0] = 0;
    d[1] = (ll)-1e18;
    for (int i = 0; i < sz(ans); i++) {
        nd[0] = max(d[0] + ans[i].first, d[1] + ans[i].second);
        nd[1] = max(d[1] + ans[i].first, d[0] + ans[i].second);
        swap(nd, d);
    }
    res.first = d[0];
    res.second = max(d[1], d[0] + a[v]);
    return res;
}

bool main_impl() {
    int n;
    if (scanf("%d", &n) < 1) return 0;
    for (int i = 0; i < n; i++) {
        c[i].clear();
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&p[i],&a[i]);
        p[i]--;
        if (p[i] >= 0) {
            c[p[i]].push_back(i);
        }
    }
    pair<ll, ll> res = go(0);
    printf(LLD "\n", max(res.first, res.second));
    return 1;
}

int main() {
    srand(rdtsc());
    while(main_impl());
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}