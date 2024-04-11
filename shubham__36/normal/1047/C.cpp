#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
string s;
ll b[15000001];



ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


#define MAXN   15000001

// stores smallest prime factor for every number
ll spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

/*
// driver program for above function
int main(int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector <int> p = getFactorization(x);

    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}

*/




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x,y,ans=0,m=0;
    bool bo=true;
    cin >> n;
    ll a[n];
    cin >> a[0];
    ans =a[0];
    forsn(i,1,n){
        cin >> a[i];
        ans = gcd(ans,a[i]);
    }
    sieve();
    ll temp;
    forn(i,n){
        a[i]/=ans;
        vector <ll> p = getFactorization(a[i]);
        if(p.size()) {ll temp=p[0];
        forn(i,p.size()-1){
            if(temp!=p[i+1]) {b[temp]++; temp = p[i+1];}
        }
        b[temp]++;}
        if(a[i]!=1) bo = false;
    }
    if(bo) {
        cout << -1;
        return 0;
    }
    forn(i,15000001){
        m = max(m,b[i]);
    }
    cout << n-m;
    return 0;
}