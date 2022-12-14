#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<memory.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<iomanip>
#include<string.h>
#include<sstream>
#include<queue>
using namespace std;
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll >
#define vpll vector<pll >
#define matrix vvll
#define vpii vector<pii >
#define ppll pair<pll,pll >
#define PI (ld)acos(-1.0)
#define E 2.71828182845904523536
#define FOR(i,x,y) for(ll i=x;i<=y;++i)
#define REP(i,n) FOR(i,0,n-1)
#define NOMOD 1000000000000000007 // 1e18+7
ll power(ll x, ll y, ll m = NOMOD)
{
    if (!y) return 1;
    if (y % 2) return x*power(x, y - 1, m) % m;
    ll k = power(x, y / 2, m);
    return k*k %m;
}
vvll multy(vvll x, vvll y, ll m = NOMOD)
{
    vvll z;
    z.resize(x.size());
    for (int i = 0; i < z.size(); ++i) z[i].assign(y[0].size(), 0);

    for (int k = 0; k < y.size(); ++k)
    for (int i = 0; i < x.size(); ++i)
    for (int j = 0; j < y[0].size(); ++j)
        z[i][j] = (z[i][j] + x[i][k] * y[k][j]) % m;
    return z;
}
vvll power(vvll x, ll y, ll m = NOMOD)
{
    if (y == 1) return x;
    if (y % 2) return multy(x, power(x, y - 1, m), m);
    vvll k = power(x, y / 2, m);
    return multy(k, k, m);
}
ld power(ld x, ll y)
{
    return exp(log(x)*(ld)y);
}
ll gcd(ll x, ll y)
{
    return y ? gcd(y, x%y) : x;
}
ll gcdex(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcdex(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll lcm(ll x, ll y, ll m = NOMOD)
{
    return x / gcd(x, y)*y%m;
}
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i*i <= n; ++i)
    if (n % i == 0) {
        while (n % i == 0)
            n /= i;
        result -= result / i;
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll rev_el(ll a, ll m)
{
    ll x, y;
    ll g = gcdex(a, m, x, y);
    if (g != 1)
        return power(x, phi(m) - 1, m);
    else {
        x = (x % m + m) % m;
        return x;
    }

}
bool isPrime(ll x)
{
    if (x <= 1) return false;
    for (ll i = 2; i*i <= x; ++i)
    if (x%i == 0) return false;
    return true;
}
int cnt_dig(ll x)
{
    if (!x) return 1;
    int ans = 0;
    while (x)
    {
        x /= 10;
        ans++;
    }
    return ans;
}
int sum_dig(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int cnt_bit(ll x)
{
    int res = 0;
    while (x)
    {
        res += x & 1;
        x >>= 1;
    }
    return res;
}
ll sqr(ll x, ll m = NOMOD)
{
    return x*x%m;
}

#define INF 1000000007 // 1e9+7
#define EPS 1e-7
#define MOD 1000000007
#define maxn 200002
#define maxm 200002
#define ALP 27
#define HASH 31
#define pcnt 30

int n,m;
int p[maxn];
int par[maxn];
vpii a;

int boss(int v)
{
        if(v==p[v]) return v;
        else return p[v] = boss(p[v]);
}
void join(int a,int b)
{
        p[a]=b;
        par[a]=b;
}
bool isPar(int x,int y)
{
        if(x==y) return true;
        while(y!=par[y]) {
                if(x==y) return true;
                y=par[y];
        }
        return x==y;
}
void check(int x, int y)
{
        int p1 = a[y-1].first;
        int p2 = a[y-1].second;
        if(isPar(x,p1) && isPar(p2,x)) puts("YES");
        else puts("NO");
}

int main()
{
        while(scanf("%d%d",&n,&m)==2)
        {
                for(int i=1;i<=n;++i) p[i]=i, par[i]=i;
                while(m--)
                {
                        int t,x,y;
                        scanf("%d",&t);
                        if(t%2) scanf("%d%d",&x,&y);
                        else scanf("%d",&x);
                        if(t==1) join(x, y);
                        else if(t==2) a.push_back(mp(x,boss(x)));
                        else check(x,y);
                }
        }
}