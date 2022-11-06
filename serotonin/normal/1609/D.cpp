#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int c[sz], bon;
multiset <int> st;

struct dsu {
   int id[sz], r[sz];

   void init(int n) {
      for(int i=1; i<=n; i++) id[i] = i, r[i] = 1;
   }

   int root(int x) {
      return id[x] = id[x] ^ x ? root(id[x]) : x;
   }

   bool unite(int x, int y) {
      x = root(x), y = root(y);
      if(x == y) return 0;
      if(r[x] < r[y]) swap(x, y);
      st.erase(st.find(r[x]));
      st.erase(st.find(r[y]));
      r[x] += r[y]; id[y] = x;
      st.insert(r[x]);
      return 1;
   }
} mst;

int main() {
   int n, q;
   cin >> n >> q;
   mst.init(n);
   for(int i=1; i<=n; i++) st.insert(1);
   while(q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      bon += !mst.unite(x, y);
      int ans = 0;
      vector <int> ara;
      for(int i=0; i<=bon; i++) {
         if(st.empty()) break;
         int v = *st.rbegin();
         ara.push_back(v);
         st.erase(st.find(v));
      }
      for(int x : ara) st.insert(x), ans += x;
      printf("%d\n", ans - 1);
   }
}