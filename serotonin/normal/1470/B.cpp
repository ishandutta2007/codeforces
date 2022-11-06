#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[sz], bpf[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int non = 0;
   map <vector<int>, int> mp;
   for(int i=1; i<=n; i++) {
      int x = a[i];
      vector <int> now;
      while(x > 1) {
         int y = bpf[x], k = 0;
         while(x % y == 0) x /= y, k ^= 1;
         if(k & 1) now.push_back(y);
      }
      if(now.empty()) {
         non++;
         continue;
      }
      reverse(now.begin(), now.end());
      mp[now]++;
   }

   int mx = non, ev = non;
   for(auto &it : mp) {
      int y = it.second;
      mx = max(mx, y);
      if(y % 2 == 0) ev += y;
   }
   ev = max(ev, mx);

   int q;
   ll x;
   scanf("%d", &q);
   while(q--) {
      scanf("%lld", &x);
      if(!x) printf("%d\n", mx);
      else printf("%d\n", ev);
   }
}

void sieve() {
   for(int i=2; i<sz; i++) {
      if(bpf[i]) continue;
      for(int j=i; j<sz; j+=i) bpf[j] = i;
   }
}

int main() {
   sieve();
   int t;
   cin >> t;
   while(t--) solve();
}