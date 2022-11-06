#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

int a[sz], b[sz];

int fnc(int v) {
   int d = 0;
   while(v) v /= 10, d++;
   return d;
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);
   map <int,int> mp;
   for(int i=0; i<n; i++) mp[a[i]]++, mp[b[i]]--;
   
   int ans = 0;
   while(!mp.empty()) {
      int v = mp.rbegin()->first;
      int c = mp[v];
      mp.erase(v);
      if(c) {
         v = fnc(v);
         mp[v] += c;
         ans += abs(c);
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}