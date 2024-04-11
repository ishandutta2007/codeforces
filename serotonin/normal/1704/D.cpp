#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll cnt[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   vector <vector<ll>> a(n);
   for(int i=0; i<n; i++) {
      a[i].resize(m);
      for(int j=0; j<m; j++) scanf("%lld", &a[i][j]);
   }

   map <ll,int> mpc;
   for(int i=0; i<n; i++) {
      ll sum = 0;
      for(ll x : a[i]) sum += x;
      sum >>= 1;

      cnt[i] = 0;
      for(int j=0; j<m; j++) {
         ll x = a[i][j];
         if(x <= sum) cnt[i] += x * j, sum -= x;
         else if(!sum) cnt[i] -= x * (m - 1 - j);
         else {
            cnt[i] += sum * j;
            cnt[i] -= (x - sum) * (m - 1 - j);
            sum = 0;
         }
      }
      mpc[cnt[i]]++;
   }

   for(int i=0; i<n; i++) assert(mpc[cnt[i]] == 1 or mpc[cnt[i]] == n - 1);

   for(int i=0; i<n; i++) if(mpc[cnt[i]] == 1) {
      printf("%d ", i + 1);
      ll x = mpc.begin()->first;
      mpc.erase(mpc.begin());
      ll y = mpc.begin()->first;
      if(x > y) swap(x, y);
      printf("%lld\n", abs(x - y));
      return;
   }
   assert(0);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}