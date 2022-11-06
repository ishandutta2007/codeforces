#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5,mod=1e9+7;

bool ara[sz];
vector <ll> primes;

void makePrimes()
{
    for(ll i=2; i<sz; i++) {
        if(!ara[i]) {
            primes.push_back(i);
            for(ll j=i*i; j<sz; j+=i) ara[j]=1;
        }
    }
}

vector <ll> a;

ll iterBigmod(ll b, ll n)
{
    ll ans=1;
    while(n) {
        if(n&1LL) ans=(ans*b)%mod;
        n>>=1LL;
        b=(b*b)%mod;
    }
    return ans;
}

int main()
{
    makePrimes();
    ll n,x;
    cin >> x >> n;
    for(ll i=0; i<primes.size(); i++) {
      if(x%primes[i]==0) {
         a.push_back(primes[i]);
         while(x%primes[i]==0) x/=primes[i];
      }
    }
    if(x>1) a.push_back(x);

    ll ans=1;
    for(ll i=0; i<a.size(); i++) {
      ll p=a[i];
      for(ll j=p, k=1; ; j*=p, k++) {
         ll now=n/j;
         ll res=now-now/p;
         ll bm=iterBigmod(p,res*k);
         ans=(ans*bm)%mod;
         if(n/p<j) break;
      }
    }
    cout << ans << endl;
}