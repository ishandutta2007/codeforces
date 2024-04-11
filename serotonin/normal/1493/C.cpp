#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[sz], ans[sz];

void solve() {
   int n, k;
   scanf("%d %d %s", &n, &k, s);
   if(n % k) {
      puts("-1");
      return;
   }
   int a[26] = {};
   for(int i=0; i<n; i++) a[s[i] - 'a']++;

   bool yes = 1;
   for(int i=0; i<26; i++) if(a[i] % k) yes = 0;
   if(yes) {
      puts(s);
      return;
   }

   for(int i=n-1; i>=0; i--) {
      int x = s[i] - 'a';
      a[x]--;
      for(int j=x+1; j<26; j++) {
         a[j]++;
         int mn = 0;
         int b[26];
         for(int e=0; e<26; e++) {
            int c = a[e] % k;
            if(c) c = k - c;
            mn += c;
            b[e] = c;
         }
         if(mn <= n-1-i) {
            int pos = n-1;
            ans[n] = 0;
            for(int e=25; e>=0; e--) {
               while(b[e]--) ans[pos--] = 'a' + e;
            }
            while(pos > i) ans[pos--] = 'a';
            ans[i] = 'a' + j;
            for(int e=0; e<i; e++) ans[e] = s[e];
            puts(ans);
            return;
         }
         a[j]--;
      }
   }

   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}