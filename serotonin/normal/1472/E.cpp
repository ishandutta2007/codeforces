#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz];
int ans[sz];
vector <pii> quer[sz], add[sz];

void solve() {
   int n, k = 1;
   scanf("%d", &n);
   map <int,int> mp;
   for(int i=0; i<n; i++) {
      scanf("%d %d", &a[i].x, &a[i].y);
      mp[a[i].x] = mp[a[i].y] = 1;
      ans[i] = -1;
   }
   for(auto &it : mp) it.y = k++;
   for(int i=0; i<n; i++) {
      a[i].x = mp[a[i].x];
      a[i].y = mp[a[i].y];
      quer[a[i].y].emplace_back(a[i].x, i);
      quer[a[i].x].emplace_back(a[i].y, i);
      add[a[i].x].emplace_back(a[i].y, i);
   }

   int who = -1, what = INT_MAX;
   for(int i=1; i<k; i++) {
      for(auto &p : quer[i]) if(what < p.x) ans[p.y] = who;
      for(auto &p : add[i]) if(p.x < what) what = p.x, who = p.y;
      quer[i].clear(), add[i].clear();
   }

   for(int i=0; i<n; i++) {
      if(ans[i] < 0) printf("-1 ");
      else printf("%d ", ans[i] + 1);
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}