#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], big;
map <int,int> g;
vector<int> gg[sz];

int fnc(vector <int> ara) {
   int mx = 0, msk = 0;
   for(int i=big; i>=0; i--) {
      msk |= 1 << i;
      set <int> st;
      for(int &x : ara) st.insert(x & msk);
      int now = mx | 1 << i;
      for(int x : st) {
         if(st.count(now ^ x)) {
            mx = now;
            break;
         }
      }
   }
   return mx;
}

int main() {
   int n, k;
   cin >> n >> k;
   map <int,int> mp;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), mp[a[i]] = i;

   if(!k) {
      printf("%d\n", n);
      for(int i=1; i<=n; i++) printf("%d ", i);
      return 0;
   }

   int b = 31 - __builtin_clz(k), e = 0;
   for(int i=1; i<=n; i++) {
      int m = 0;
      for(int j=b; j<30; j++) if(a[i] & 1 << j) {
         m |= 1 << j;
      }
      if(!g[m]) g[m] = ++e;
      gg[g[m]].push_back(a[i]);
   }

   big = b, b = 1 << b;
   vector <int> ans;
   for(auto &[idk, idx] : g) {
      auto &vec = gg[idx];
      if(idk & b) {
         if(g.find(idk ^ b) == g.end()) ans.push_back(vec.back());
         continue;
      }
      if(g.find(idk | b) == g.end()) ans.push_back(vec.back());
      else {
         auto &oth = gg[g[idk | b]];
         for(int &x : oth) vec.push_back(x);
         int now = fnc(vec);
         if(now >= k) {
            set <int> st;
            for(int x : vec) st.insert(x);
            for(int x : vec) {
               if(st.count(x ^ now)) {
                  ans.push_back(x ^ now);
                  ans.push_back(x);
                  break;
               }
            }
         }
         else ans.push_back(oth.back());
      }
   }

   if(ans.size() < 2) puts("-1");
   else {
      printf("%d\n", ans.size());
      for(int x : ans) printf("%d ", mp[x]);
   }
}