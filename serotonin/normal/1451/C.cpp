#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

char sa[sz], sb[sz];

void solve() {
   int a[30] = {}, b[30] = {};
   int n, k;
   scanf("%d %d", &n, &k);
   scanf("%s %s", sa, sb);
   for(int i=0; i<n; i++) a[sa[i] - 'a']++;
   for(int i=0; i<n; i++) b[sb[i] - 'a']++;

   for(int i=0; i<26; i++) {
      int x = a[i] - b[i];
      if(x < 0 || x % k) {
         puts("No");
         return;
      }
      a[i+1] += x;
   }
   puts("Yes");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}