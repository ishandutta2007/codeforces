#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int a[sz<<1];

void solve()
{
   int n;
   scanf("%d", &n);
   vector <int> od, ev;
   for(int i=1; i<=2*n; i++) {
      scanf("%d", &a[i]);
      if(a[i] & 1) od.push_back(i);
      else ev.push_back(i);
   }

   vector <int> ans;
   for(int i=1; i<od.size(); i+=2) ans.push_back(od[i]), ans.push_back(od[i-1]);
   for(int i=1; i<ev.size(); i+=2) ans.push_back(ev[i]), ans.push_back(ev[i-1]);

   for(int i=0; i<n-1; i++) printf("%d %d\n", ans[i<<1], ans[i<<1|1]);
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}