#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=7005;

ll a[sz], b[sz], c[sz], n;
bool vis[sz];
vector < pair <ll,ll> > p;

void fnc(int x)
{
   vis[x]=1;
   for(int i=0; i<n; i++) {
      if(vis[i]) continue;
      if((a[i]|a[x])==a[x]) {
         c[i]--;
      }
   }

   p.clear();
   for(int i=0; i<n; i++) {
      if(vis[i]) continue;
      p.push_back({c[i],i});
   }
   sort(p.begin(), p.end());
}

int main()
{
   cin >> n;
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);
   for(int i=0; i<n; i++) scanf("%lld", &b[i]);

   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(i==j) continue;
         if((a[i]|a[j])==a[j]) {
           c[i]++;
         }
      }
   }

   for(int i=0; i<n; i++) p.push_back({c[i],i});
   sort(p.begin(), p.end());

   ll ans=0;
   for(int i=0; i<n-1; i++) {
      if(!p[0].first) {
         fnc(p[0].second);
      }
      else {
         for(int j=0; j<p.size(); j++) {
            ans+=b[p[j].second];
         }
         break;
      }
   }

   cout << ans << endl;
}