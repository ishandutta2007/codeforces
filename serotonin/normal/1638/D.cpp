#include<bits/extc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int n, m, a[sz][sz], d[sz][sz];
bool done[sz][sz];
queue <pair<int,int>> q;

void fnc(int i, int j) {
   set <int> st;
   st.insert(a[i][j]);
   st.insert(a[i+1][j]);
   st.insert(a[i][j+1]);
   st.insert(a[i+1][j+1]);
   st.erase(0);
   d[i][j] = st.size();
   if(d[i][j] == 1) {
      done[i][j] = 1;
      q.emplace(i, j);
   }
}

int who(int i, int j) {
   set <int> st;
   st.insert(a[i][j]);
   st.insert(a[i+1][j]);
   st.insert(a[i][j+1]);
   st.insert(a[i+1][j+1]);
   st.erase(0);
   if(st.empty()) return 0;
   return *st.begin();
}

vector <tuple<int,int,int>> res;

void fix(int x, int y) {
   for(int i=x-1; i<=x+1; i++) {
      for(int j=y-1; j<=y+1; j++) {
         if(i <= 0 or j <= 0 or i >= n or j >= m or done[i][j]) continue;
         fnc(i, j);
      }
   }
}

int main() {
   cin >> n >> m;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         scanf("%d", &a[i][j]);
      }
   }

   for(int i=1; i<n; i++) {
      for(int j=1; j<m; j++) {
         fnc(i, j);
      }
   }

   while(!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      int k = who(i, j);
      if(!k) continue;
      res.emplace_back(i, j, k);
      a[i][j] = 0;
      a[i+1][j] = 0;
      a[i][j+1] = 0;
      a[i+1][j+1] = 0;

      fix(i, j);
   }

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         if(a[i][j]) {
            puts("-1");
            return 0;
         }
      }
   }

   printf("%d\n", res.size());
   reverse(res.begin(), res.end());
   for(auto [i, j, c] : res) printf("%d %d %d\n", i, j, c);
}