#include<bits/extc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int n, q, col[sz];
vector <pair<int,int>> val[sz], beg[sz], fin[sz];
vector <pair<int,ll>> cum[sz];
vector <int> quers[sz];
ll curadd[sz], bit[sz], ans[sz];
bool hmm[sz];

void add(int x, ll v) {
   while(x <= q) {
      bit[x] += v;
      x += x & -x;
   }
}

ll query(int x) {
   ll res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void fnc(int l, int r) {
   int c = col[l];
   int i = upper_bound(cum[c].begin(), cum[c].end(), make_pair(l, 0LL)) - cum[c].begin();
   int j = upper_bound(cum[c].begin(), cum[c].end(), make_pair(r, 0LL)) - cum[c].begin();
   if(i >= j) {
      curadd[l] = 0;
      return;
   }
   curadd[l] = cum[c][i].second - cum[c][j].second;
   add(l, curadd[l]);
}

ll sum(int l, int r) {
   int c = col[l];
   int i = upper_bound(cum[c].begin(), cum[c].end(), make_pair(l, 0LL)) - cum[c].begin();
   int j = upper_bound(cum[c].begin(), cum[c].end(), make_pair(r, 0LL)) - cum[c].begin();
   if(i >= j) return 0;
   return cum[c][i].second - cum[c][j].second;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);

   cin >> n >> q;

   beg[1].emplace_back(1, 1);
   col[1] = 1;
   q++;

   string s;
   for(int i=2; i<=q; i++) {
      cin >> s;
      if(s == "Color") {
         int l, r, c;
         cin >> l >> r >> c;
         beg[l].emplace_back(i, c);
         fin[r + 1].emplace_back(i, c);
         col[i] = c;
      }
      else if(s == "Add") {
         int c, x;
         cin >> c >> x;
         val[c].emplace_back(i, x);
      }
      else {
         int id;
         cin >> id;
         quers[id].push_back(i);
         hmm[i] = 1;
      }
   }

   for(int i=1; i<=n; i++) {
      reverse(val[i].begin(), val[i].end());
      ll v = 0;
      cum[i].emplace_back(q + 1, v);
      for(auto [j, x] : val[i]) {
         v += x;
         cum[i].emplace_back(j, v);
      }
      reverse(cum[i].begin(), cum[i].end());
   }

   set <int> st; st.insert(q + 1);
   for(int k=1; k<=n; k++) {
      for(auto [i, c] : beg[k]) {
         st.insert(i);
         fnc(i, *st.upper_bound(i));
         auto it = st.lower_bound(i);
         if(it == st.begin()) continue;
         int j = *prev(it);
         add(j, -curadd[j]);
         fnc(j, i);
      }
      for(auto [i, c] : fin[k]) {
         st.erase(i);
         add(i, -curadd[i]);
         auto it = st.lower_bound(i);
         if(it == st.begin()) continue;
         int j = *prev(it);
         add(j, -curadd[j]);
         fnc(j, *st.upper_bound(j));
      }
      
      for(int i : quers[k]) {
         auto it = st.lower_bound(i);
         if(it == st.begin()) continue;
         it = prev(it);

         int j = *it;
         ans[i] = query(j - 1) + sum(j, i);
         // if(k == 2) printf("%d %d\n", j, i);
      }
   }

   for(int i=1; i<=q; i++) if(hmm[i]) cout << ans[i] << '\n';
}