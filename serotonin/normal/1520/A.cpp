#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int a[30], b[30];
char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   memset(a, -1, sizeof a);
   for(int i=0; i<n; i++) a[s[i] - 'A'] = i;
   for(int i=n-1; i>=0; i--) b[s[i] - 'A'] = i;

   for(int i=0; i<26; i++) {
      if(a[i] < 0) continue;
      for(int j=b[i]; j<=a[i]; j++) if(s[j] - 'A' != i) {
         puts("NO");
         return;
      }
   }
   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}