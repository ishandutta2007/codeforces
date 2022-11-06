#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const int sz = 2e5+5;

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

gp_hash_table <ll,ll,chash> st, mp;

int main() {
   int q;
   cin >> q;
   st[0] = 1;
   while(q--) {
      ll x;
      char s[5];
      scanf("%s %lld", s, &x);
      if(s[0] == '+') st[x] = 1;
      else {
         while(st.find(mp[x]) != st.end()) mp[x] += x;
         printf("%lld\n", mp[x]);
      }
   }
}