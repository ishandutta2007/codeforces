#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

const int N = 500 * 1000 + 5;
int n, q;
int cnt[N];
int a[N];

bool read() {
    scanf("%d%d", &n, &q);
    forn (i, n)
        scanf("%d", &a[i]);
    return false;
}

int d[N];
li ans = 0;

vector<int> primes(int x) {
    vector<int> res;
    while(x > 1) {
        res.pb(d[x]);
        x /= d[x];
    }
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
    return res;
}

void go(int x, int d) {
    vector<int> p = primes(x);
    forn (i, 1 << p.size()) {
        int cur = 1;
        int t = 0;
        forn (j, p.size())
            if (i & (1 << j))
                cur *= p[j], t ^= 1;

        if (d > 0) {
            if (t)
                ans -= cnt[cur];
            else
                ans += cnt[cur];
            cnt[cur]++;
        } else {
            cnt[cur]--;
            if (t)
                ans += cnt[cur];
            else
                ans -= cnt[cur];
        }
    }
}

bool u[N];

void solve() {

    for (int i = 2; i < N; ++i) {
        if (d[i] == 0) {
            for (int j = i; j < N; j += i)
                d[j] = i;
        }
    }

    forn (i, q) {

        int j;
        scanf("%d", &j);
        j--;
        if (u[j])
            go(a[j], -1);
        else
            go(a[j], +1);
        u[j] ^= true;
        printf("%I64d\n", ans);     
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();
    
    return 0;
}