#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+7;

int az[11];
vector <int> a[11];
vector <vector<int>> ban;
map <int,int> mp[sz];
bool done[sz];

int main() {
   int n;
   cin >> n;

   ll big = 0;
   for(int i=0; i<n; i++) {
      int c;
      scanf("%d", &c); az[i] = c;
      a[i].resize(c);
      for(int j=0; j<c; j++) scanf("%d", &a[i][j]);
      big += a[i].back();
   }

   int m;
   cin >> m;
   ban.resize(m);
   for(int i=0; i<m; i++) {
      ban[i].resize(n);
      for(int j=0; j<n; j++) scanf("%d", &ban[i][j]);
   }

   if(!m) {
      for(int j=0; j<n; j++) printf("%d ", az[j]);
      return 0;
   }

   int tk = 0;
   for(int i=0; i<m; i++) {
      int u = 0;
      for(int j=0; j<n; j++) {
         int x = ban[i][j];
         if(mp[u].find(x) == mp[u].end()) mp[u][x] = ++tk;
         u = mp[u][x];
      }
   }

   vector <int> id(n, 0);
   pair <ll,vector<int>> ans = make_pair(0LL, id);

   for(int i=0; i<m; i++) {
      int u = 0;
      ll sum = big;
      for(int j=0; j<n; j++) id[j] = az[j];
      for(int j=0; j<n; j++) {
         if(!done[u]) {
            done[u] = 1;
            int b = az[j];
            while(b) {
               if(mp[u].find(b) == mp[u].end()) {
                  id[j] = b;
                  ll now = sum + a[j][b-1] - a[j].back();
                  ans = max(ans, make_pair(now, id));
                  break;
               }
               b--;
            }
         }

         int x = ban[i][j]; id[j] = x;
         sum += a[j][x-1] - a[j].back();
         u = mp[u][x];
      }
   }

   for(int x : ans.second) printf("%d ", x);
}