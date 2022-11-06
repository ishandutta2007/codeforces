#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const int sz = 4e5+5;

struct chash {
   static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
   }
};

gp_hash_table <ll,vector<int>,chash> mp, quers;
set <ll> here;

char s[sz][5];
ll val[sz], ans[sz];
int idx[sz];

int main() {
   int q;
   cin >> q;
   for(int i=1; i<=q; i++) scanf("%s %lld", s[i], &val[i]);
   
   for(int i=1; i<=q; i++) {
      if(s[i][0] == '?') quers[val[i]].push_back(i);
      else mp[val[i]].push_back(i);
   }

   for(auto &[v, vec] : quers) {
      int k = 0;
      here.clear();
      for(ll now = v; ; now += v) {
         if(mp.find(now) == mp.end()) {
            while(now) here.insert(now), now -= v;
            break;
         }
         else {
            auto &ara = mp[now];
            for(int &i : ara) idx[k++] = i;
         }
      }
      for(int &i : vec) idx[k++] = i;
      sort(idx, idx + k);
      for(int e = 0; e < k; e++) {
         int i = idx[e];
         if(s[i][0] == '+') here.erase(val[i]);
         else if(s[i][0] == '-') here.insert(val[i]);
         else ans[i] = *here.begin();
      }
   }

   for(int i=1; i<=q; i++) if(s[i][0] == '?') printf("%lld\n", ans[i]);
}