#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

typedef pair <int, int> pii;
#define x first
#define y second

int a[sz], b[sz];

void solve()
{
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);

   vector <pii> od, ev;
   int z = (n + 1) >> 1;
   for(int i=0; i<z; i++) {
      od.push_back({a[i], a[n-1-i]});
      ev.push_back({b[i], b[n-1-i]});
   }

   for(int i=0; i<z; i++) {
      if(od[i].x > od[i].y) swap(od[i].x, od[i].y);
      if(ev[i].x > ev[i].y) swap(ev[i].x, ev[i].y);
   }

   sort(od.begin(), od.end());
   sort(ev.begin(), ev.end());

   bool no = 0;
   for(int i=0; i<z; i++) if(od[i] != ev[i]) no = 1;

   if(no) puts("No");
   else puts("Yes");
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}