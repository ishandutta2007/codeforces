#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7, mod = 1e9+7;

ll sum[sz];
vector <int> g[sz], dvs[sz];

ll hmm[sz];
int now[sz], cnt[sz];
bool ya[sz];

ll fnc(vector <int> &ara) {
   int k = 0;
   for(int &x : ara) {
      for(int &d : dvs[x]) {
         if(!ya[d]) now[k++] = d, ya[d] = 1;
         cnt[d]++;
      }
   }
   ll ans = 0;
   sort(now, now + k);
   for(int i=k-1; i>=0; i--) {
      int d = now[i]; ll c = cnt[d]; cnt[d] = ya[d] = 0;
      ll &v = hmm[d];
      v += c * c; v %= mod;
      for(int &j : dvs[d]) if(ya[j]) hmm[j] -= v;
      ans += d * v % mod; v = 0;
   }
   return ans % mod;
}

int main() {
   for(int i=1; i<sz; i++) {
      for(int j=i; j<sz; j+=i) dvs[j].push_back(i);
   }

   int n;
   cin >> n;
   for(int j=1; j<=n; j++) {
      int x;
      scanf("%d", &x);
      for(int i : dvs[x]) g[i].push_back(j);
   }

   ll ans = 0;
   for(int k=sz-1; k; k--) {
      sum[k] = fnc(g[k]);
      for(int i=k<<1; i<sz; i+=k) sum[k] -= sum[i];
      sum[k] %= mod;
      ans += sum[k] * k % mod;
      ans %= mod;
   }
   ans += mod; ans %= mod;
   cout << ans;
}