#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;
int dp[300][300];

void solve(int o, int z, int n, int k) {
    if (n == k) {
        if (o % 2 == 0) {
        cout << "Daenerys\n";
        } else {
       //     return 1;
            cout << "Stannis\n";
        }
        return;
    }

    int st = (n - k) / 2;
    int w = 1;
    if ((n - k) % 2 == 1)
        w = 0;
    bool win = false;
    if (z <= st && k % 2 == w)
        win = true;
    if (o <= st && w == 0)
        win = true;
    if (win ^ (w == 1)) {
//        return 0;
        cout << "Daenerys\n";
    } else {
   //     return 1;
        cout << "Stannis\n";
    }
}
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    
    int n, k;
    scanf("%d%d", &n, &k);
    int z = 0;
    int o = 0;
    FOR(i, n) {
        int a;
        scanf("%d", &a);
        if (a % 2 == 0)
            z++;
        else
            o++;
    }
    solve(o, z, n, k);
    /*
    FOR(k, 100) {
        FOR(o, k + 1) {
            dp[o][k - o] = (o % 2 == 1);
        }
        for(int n = k + 1; n < 200; ++n) {
            FOR(o, n) {
                int z = n - o;
                if (o > 0 && dp[o - 1][z] == 0 || z > 0 && dp[o][z - 1] == 0)
                    dp[o][z] = 1;
                else
                    dp[o][z] = 0;
                cerr << n << ' ' << k << ' ' << o << ' ' << z << '\n';
                cerr << dp[o][z] << '\n';
                assert(dp[o][z] == solve(o, z, n, k));

            }
        }
    }*/
    return 0;
}