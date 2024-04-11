#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

char s[sz];
vector <ll> primes;
bitset <sz> vis;

void sieve() {
   for(int i=2; i<sz; i++) {
      if(vis[i]) continue;
      primes.push_back(i);
      for(int j=i; j<sz; j+=i) vis[j] = 1;
   }
}

void solve() {
   ll d;
   scanf("%lld", &d);
   int x = lower_bound(primes.begin(), primes.end(), d + 1) - primes.begin();
   ll p1 = primes[x];
   int y = lower_bound(primes.begin(), primes.end(), d + p1) - primes.begin();
   ll p2 = primes[y];
   printf("%lld\n", p1 * p2);
}

int main() {
   sieve();
   int t;
   cin >> t;
   while(t--) solve();
}