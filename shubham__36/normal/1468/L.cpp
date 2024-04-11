#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
// using namespace atcoder;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// #define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mll modll998244353
 
ll mpow(ll a, ll b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll t1 = mpow(a, b / 2);
    t1 *= t1;
    t1 %= MOD;
    if (b % 2)
        t1 *= a;
    t1 %= MOD;
    return t1;
}
 
ll mpow(ll a, ll b, ll p)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll t1 = mpow(a, b / 2, p);
    t1 *= t1;
    t1 %= p;
    if (b % 2)
        t1 *= a;
    t1 %= p;
    return t1;
}
 
ll modinverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
 
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r)
{
    return l + mt() % (r - l + 1);
}
 
ll rev(ll v)
{
    return mpow(v, MOD - 2);
}
 
ll ceil(ll p, ll q)
{
    return (p + q - 1) / q;
}

bool isPerfect(ll n, ll p)
{
    ll clos = n;
    while(clos % p == 0) clos /= p;
    // while(clos < n) clos *= p;
    // if(clos == n) return true;
    return (clos == 1);
}
bool isComb(ll n, v64 prims)
{
    ll cp = n;
    forn(i, prims.size())
    {
        while(cp%prims[i] == 0)
        {
            cp /= prims[i];
        }
    }
    // cout<<"inside it";
    // cout<<n;
    // forn(i, prims.size())
    // {
    //     cout<<prims[i]<<" ";
    // }
    // cout<<ln<<(cp == 1)<<ln;
    return (cp == 1);
}
v64 whichComb(ll n, v64 prims)
{
    v64 out;
    ll cp = n;
    forn(i, prims.size())
    {
        if(cp%prims[i] == 0)
        {
            out.pb(prims[i]);
            while(cp%prims[i] == 0)
            {
                cp /= prims[i];
            }
        }
    }
    return out;
}

void solve()
{
    ll n,k;cin>>n>>k;
    v64 num(n);
    forn(i, n)
    {
        cin>>num[i];
    }
    if(k == 1)
    {
        cout<<0<<ln;
        exit(0);
    }
    v64 primes;
    v64 isPrime(1000000, 1);
    forsn(i, 2, 1000000)
    {
        forsn(j, 2, 1000000)
        {
            if(i*j >= 1000000) break;
            isPrime[i*j] = 0;
        }
    }
    forsn(i, 2, 1000000)
    {
        if(isPrime[i] == 1) primes.pb(i);
    }
    forn(i, n)
    {
        bool flg = 1;
        forn(j, primes.size())
        {
            if(num[i]%primes[j] == 0)
            {
                flg = 0;
            }
        }
        if(num[i] < 1000000000 && flg)
        {
            primes.pb(num[i]);
        }
    }
    v64 pcount(primes.size(), 0);
    vv64 actnum(primes.size());
    v64 selected(n, 0);
    map<ll, ll> temp, temp1;
    forn(j, primes.size())
    {
        ll curr = primes[j];
        while(curr < 1e19)
        {
            temp[curr] = primes[j];
            if(curr > (1e18/primes[j])+1) break;
            curr *= primes[j];
        }
    }
    forn(i, primes.size())
    {
        temp1[primes[i]] = i;
    }
    forn(i, n)
    {
        if(temp[num[i]])
        {
            selected[i] = 1;
            actnum[temp1[temp[num[i]]]].pb(num[i]);
            pcount[temp1[temp[num[i]]]]++;
        }
        // forn(j, primes.size())
        // {
        //     if(isPerfect(num[i], primes[j]))
        //     {
        //         selected[i] = 1;
        //         actnum[j].pb(num[i]);
        //         pcount[j]++;
        //     }
        // }
    }
    v64 spPrimes;
    v64 ans;
    v64 waiting;
    if(k%2 == 1)
    {
        bool flg = 0;
        forn(i, primes.size())
        {
            if(pcount[i] > 1)
            {
                spPrimes.pb(primes[i]);
                ans.pb(actnum[i][0]);
                ans.pb(actnum[i][1]);
                forsn(k, 2, actnum[i].size())
                {
                    waiting.pb(actnum[i][k]);
                }
            }
        }
        // forn(i, ans.size())
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<ln;
        if(ans.size() > k)
        {
            if(waiting.size() == 0)
            {
                map<ll, bool> pm;
                forn(i, n)
                {
                    if(selected[i] == 0)
                    {
                        if(isComb(num[i], spPrimes))
                        {
                            v64 wprimes = whichComb(num[i], spPrimes);
                            if(wprimes.size() <= k/2)
                            {
                                v64 ans, waiting;
                                ans.pb(num[i]);
                                forn(i, wprimes.size())
                                {
                                    pm[wprimes[i]] = 1;    
                                }
                                forn(i, primes.size())
                                {
                                    if(pcount[i] > 1)
                                    {
                                        if(pm[primes[i]])
                                        {
                                            ans.pb(actnum[i][0]);
                                            ans.pb(actnum[i][1]);
                                        }
                                        else
                                        {
                                            waiting.pb(actnum[i][0]);
                                            waiting.pb(actnum[i][1]);
                                        }
                                    }
                                }
                                forn(i, waiting.size())
                                {
                                    ans.pb(waiting[i]);
                                }
                                forn(i, k)
                                {
                                    cout<<ans[i]<<" ";
                                }
                                cout<<ln;
                                exit(0);
                            }
                        }
                    }
                }
                cout<<0<<ln;
            }
            else
            {
                v64 ans;
                forn(i, primes.size())
                {
                    if(pcount[i] > 1)
                    {
                        if(ans.size()+2 <= k)
                        {
                            ans.pb(actnum[i][0]);
                            ans.pb(actnum[i][1]);
                        }
                    }
                    if(pcount[i] > 2)
                    {
                        if(ans.size()%2 == 0)
                        {
                            ans.pb(actnum[i][2]);
                        }
                    }
                }
                forn(i, k)
                {
                    cout<<ans[i]<<" ";
                }
                cout<<ln;
            }
            exit(0);   
        }        
        forn(i, n)
        {
            //cout<<i<<" "<<num[i]<<" "<<selected[i]<<ln;
            if(selected[i] == 0)
            {
                if(isComb(num[i], spPrimes))
                {
                    waiting.pb(num[i]);
                }
            }
        }
        forn(i, waiting.size())
        {
            ans.pb(waiting[i]);
        }
        if(ans.size() < k)
        {
            cout<<0<<ln;
        }
        else
        {
            forn(i, k)
            {
                cout<<ans[i]<<" ";
            }
            cout<<ln;
        }
    }
    else
    {
        forn(i, primes.size())
        {
            if(pcount[i] > 1)
            {
                spPrimes.pb(primes[i]);
                ans.pb(actnum[i][0]);
                ans.pb(actnum[i][1]);
                forsn(k, 2, actnum[i].size())
                {
                    waiting.pb(actnum[i][k]);
                }
            }
        }
        forn(i, n)
        {
            if(selected[i] == 0)
            {
                if(isComb(num[i], spPrimes))
                {
                    waiting.pb(num[i]);
                }
            }
        }
        forn(i, waiting.size())
        {
            ans.pb(waiting[i]);
        }
        if(ans.size() < k)
        {
            cout<<0<<ln;
        }
        else
        {
            forn(i, k)
            {
                cout<<ans[i]<<" ";
            }
            cout<<ln;
        }
    }

}
 
int main()
{
    fast_cin();
    ll t = 1;
    //cin >> t;
    forn(i, t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}