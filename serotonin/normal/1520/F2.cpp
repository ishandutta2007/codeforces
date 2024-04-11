#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mz = 30;

bool done[sz];

int n, wut[sz], bit[sz];

int quer(int x) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void upd(int x) {
   while(x <= n) {
      bit[x]++;
      x += x & -x;
   }
}

int ask(int r) {
   if(done[r]) return wut[r] - quer(r);
   printf("? 1 %d\n", r); fflush(stdout);
   int sum;
   scanf("%d", &sum);
   done[r] = 1;
   wut[r] = r - sum + quer(r);
   return r - sum;
}

int main() {
   int t, k;
   cin >> n >> t >> k;
   vector <int> ara(1, 0), who(1, 0);
   for(int i=mz; i<=n; i+=mz) {
      ara.push_back(ask(i));
      who.push_back(i);
   }
   while(t--) {
      int j = lower_bound(ara.begin(), ara.end(), k) - ara.begin();

      int lo = who[j-1] + 1, hi = n;
      if(j < ara.size()) hi = who[j];
      lo = min(lo, hi);

      while(lo < hi) {
         int md = lo + hi >> 1;
         if(ask(md) < k) lo = md + 1;
         else hi = md;
      }

      printf("! %d\n", lo); fflush(stdout);

      upd(lo);
      for(; j<ara.size(); j++) ara[j]--;

      if(t) scanf("%d", &k);
   }
}