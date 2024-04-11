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

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e6 + 100;

int cp = 0;
ll primes[MAXN];
bool isp[MAXN];
ll divs[MAXN];
ll dp[MAXN];

bool isprime(ll d) {
    FOR(i, cp) {
        if (d % primes[i] == 0)
            return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    
    for (int i = 2; i < MAXN; ++i) {
        isp[i] = true;
    }
    for (int i = 2; i < MAXN; ++i) {
        if (!isp[i])
            continue;
        primes[cp++] = i;

        for (int j = i + i; j < MAXN; j += i) {
            isp[j] = false;
        }
    }
    ll a;
    cin >> a;
//    for (ll a = 1; a < 1000; ++a) {  
    int m = 0;
    for (ll i = 1; i * i <= a; ++ i) {
        if (a % i == 0) {
            divs[m++] = i;
            if (i * i < a) {
                divs[m++] = a / i;
            }
        }
    }
    sort(divs, divs + m);
    /*
    FOR(i, m) {
        cerr << divs[i] << '\n';
    }*/
    set<ll> sd;
    FOR(i, m) {
        sd.insert(divs[i]);
    }
    vector<vector<ll> > good;
    FOR(i, cp) {
        ll pw = primes[i];
        vector<ll> v;
        while (true) {
            if (sd.count(pw + 1) != 0) {
                sd.erase(pw + 1);
                v.push_back(pw + 1);
            }
            if (pw * primes[i] > a)
                break;
            pw *= primes[i];
        }
        if (v.size() > 0)
            good.push_back(v);
    }
    for (auto d : sd) {
        if (d < MAXN)
            continue;
        if (isprime(d - 1)) {
            good.push_back(vector<ll>{d});
        }
    }
    /*
    cerr << "!!!";
    
    for (auto p : good) {
        cerr << p << '\n';
    }*/
    map<ll, int> ton;
    FOR(i, m) {
        ton[divs[i]] = i;
    }
    clr(dp);
    dp[0] = 1;
    for (auto v : good) {
        for (int i = m - 1; i >= 0; --i) {
            if (dp[i] == 0)
                continue;
            for (auto j : v) {
                if (a / j + 1< divs[i])
                    continue;
                ll dest = divs[i] * j;
                if (a % dest == 0) {
                    int nm = ton[dest];
        //            cerr << nm << ' ' << i << '\n';
                    dp[nm] += dp[i];
                }
            }
        }
    }
    /*
    ll a1 = 0;
    for (ll i = 1; i <= a; ++i) {
        ll sum = 0;
        for (ll j = 1; j <= i; ++ j) {
            if (i % j == 0 && __gcd(j, i / j) == 1) {
                sum += j;
            }
        }
        if (sum == a)
            a1++;
    }*/
  //  cerr << a << ' ' << dp[m - 1] << ' ' << a1 << '\n';
  //  assert(a1 == dp[m - 1]);
    cout << dp[m - 1] << '\n';
//    }
    return 0;
}