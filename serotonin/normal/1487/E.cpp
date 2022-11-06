#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

int n[4], ex[sz];
pii a[4][sz];
map <int,int> mp[sz];

int main() {
   for(int i=0; i<4; i++) cin >> n[i];
   for(int i=0; i<4; i++) {
      for(int j=1; j<=n[i]; j++) scanf("%d", &a[i][j].x), a[i][j].y = j;
   }
   for(int i=0; i<3; i++) {
      int m;
      scanf("%d", &m);
      for(int j=1; j<=n[i]; j++) mp[j].clear();
      while(m--) {
         int u, v;
         scanf("%d %d", &u, &v);
         mp[u][v] = 1;
      }

      set <int> st;
      for(int j=1; j<=n[i+1]; j++) st.insert(j);

      sort(a[i] + 1, a[i] + n[i] + 1);
      for(int j=1; j<=n[i]; j++) {
         int k = a[i][j].y, sum = a[i][j].x;
         if(ex[k]) continue;
         auto it = st.begin();
         while(it != st.end()) {
            if(mp[k].find(*it) == mp[k].end()) {
               a[i+1][*it].x += sum;
               it = st.erase(it);
            }
            else it++;
         }
      }
      auto it = st.begin();
      memset(ex, 0, sizeof ex);
      while(it != st.end()) {
         ex[*it] = 1;
         it++;
      }
   }
   sort(a[3] + 1, a[3] + n[3] + 1);
   for(int j=1; j<=n[3]; j++) {
      int k = a[3][j].y, sum = a[3][j].x;
      if(ex[k]) continue;
      printf("%d\n", sum);
      return 0;
   }
   puts("-1");
}