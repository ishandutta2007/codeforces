#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz], b[sz];
bool done[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) scanf("%d", &b[i]);

   for(int i=0; i<n; i++) while(~a[i] & 1) a[i] >>= 1;
   sort(a, a + n);
   reverse(a, a + n);
   set <int> need;
   for(int i=0; i<n; i++) need.insert(a[i]);

   map <int,vector<int>> mp;
   for(int i=0; i<n; i++) {
      while(~b[i] & 1) b[i] >>= 1;
      while(b[i]) {
         if(need.count(b[i])) mp[b[i]].push_back(i);
         b[i] >>= 1;
      }
      done[i] = 0;
   }

   for(int i=0; i<n; i++) {
      auto &vec = mp[a[i]];
      while(!vec.empty() and done[vec.back()]) vec.pop_back();
      if(vec.empty()) {
         puts("NO");
         return;
      }
      done[vec.back()] = 1;
   }
   puts("YES");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}