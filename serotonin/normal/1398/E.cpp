#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int sz = 2e5+5;
#define ordered_set tree <ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set st;

int tp[sz], val[sz];
ll bit[sz];

void add(int x, int v) {
   while(x) {
      bit[x] += v;
      x -= x & (-x);
   }
}

ll quer(int x) {
   ll ans = 0;
   while(x < sz) {
      ans += bit[x];
      x += x & (-x);
   }
   return ans;
}

int main() {
   int n;
   cin >> n;
   map <int,int> mp;
   for(int i=0; i<n; i++) {
      scanf("%d %d", &tp[i], &val[i]);
      if(val[i] > 0) mp[val[i]] = 1;
   }
   int k = 0;
   for(auto &d : mp) d.second = ++k;

   ll sum = 0;
   set <int> good, bad;
   for(int i=0; i<n; i++) {
      ll ans = 0;
      int v = val[i];
      if(tp[i]) {
         if(v > 0) good.insert(v);
         else good.erase(-v);
      }
      else {
         if(v > 0) bad.insert(v);
         else bad.erase(-v);
      }
      if(!good.empty()) {
         if(bad.empty())
            ans -= *good.begin();
         else if(*bad.rbegin() < *good.begin())
            ans += *bad.rbegin() - *good.begin();
      }

      sum += v;
      ans += sum;

      add(mp[abs(v)], v);

      if(v > 0) st.insert(v);
      else st.erase(-v);

      int c = good.size();
      if(c) {
         int z = st.size() - c;
         int to = *st.find_by_order(z);
         ans += quer(mp[to]);
      }
      printf("%lld\n", ans);
   }
}