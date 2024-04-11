#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

char sa[sz], sb[sz];
int n, a[sz], b[sz];
vector <pair<int,int>> ans;

void fnc(int l, int r) {
   l++, r++;

   if(r < n) {
      ans.emplace_back(l, n);
      ans.emplace_back(r + 1, n);   
   }
   else if(l > 1) {
      ans.emplace_back(1, r);
      ans.emplace_back(1, l - 1);
   }
   else {
      ans.emplace_back(1, 1);
      ans.emplace_back(2, n);
   }
}

void solve() {
   scanf("%d", &n);
   scanf("%s %s", sa, sb);

   for(int i=0; i<n; i++) a[i] = sa[i] - '0';
   for(int i=0; i<n; i++) b[i] = sb[i] - '0';

   int sem = 0, dif = 0;
   for(int i=0; i<n; i++) {
      if(a[i] == b[i]) sem++;
      else dif++;
   }

   if(sem < n and dif < n) {
      puts("NO");
      return;
   }

   ans.clear();

   if(sem == n) {
      int c = 1;
      for(int i=1; i<n; i++) {
         if(a[i] == a[i-1]) c++;
         else {
            if(a[i-1]) fnc(i - c, i - 1);
            c = 1;
         }
      }
      if(a[n-1]) fnc(n - c, n - 1);
   }
   else {
      int c = 1;
      for(int i=1; i<n; i++) {
         if(a[i] == a[i-1]) c++;
         else {
            if(!a[i-1]) fnc(i - c, i - 1);
            c = 1;
         }
      }
      if(!a[n-1]) fnc(n - c, n - 1);
      ans.emplace_back(1, n);
   }

   puts("YES");
   printf("%d\n", ans.size());
   for(auto [x, y] : ans) printf("%d %d\n", x, y);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}