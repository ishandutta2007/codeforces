#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[2][sz];
bool ya[2][sz], flag[sz];
int n, ldp[2][sz], rdp[2][sz];

void go() {
   flag[0] = flag[n+1] = 0;
   for(int i=1, f=0; i<=n; i++) {
      if(f) {
         if(ya[0][i]) {
            rdp[1][i] = 2 + min(rdp[0][i-1], rdp[1][i-1]);
            if(ya[1][i]) rdp[0][i] = 2 + min(rdp[0][i-1], rdp[1][i-1]);
            else rdp[0][i] = min(1 + rdp[0][i-1], 2 + rdp[1][i-1]);
         }
         else if(ya[1][i]) {
            rdp[0][i] = 2 + min(rdp[0][i-1], rdp[1][i-1]);
            rdp[1][i] = min(1 + rdp[1][i-1], 2 + rdp[0][i-1]);
         }
         else {
            rdp[0][i] = min(1 + rdp[0][i-1], 2 + rdp[1][i-1]);
            rdp[1][i] = min(1 + rdp[1][i-1], 2 + rdp[0][i-1]);
         }
      }
      else {
         if(ya[0][i]) {
            f = 1;
            rdp[1][i] = 1;
            if(ya[1][i]) rdp[0][i] = 1;
         }
         else if(ya[1][i]) {
            f = 1;
            rdp[0][i] = 1;
         }
      }
      flag[i] = f;
   }
}

void solve() {
   scanf("%d %s %s", &n, s[0] + 1, s[1] + 1);

   for(int j=0; j<2; j++) {
      for(int i=0; i<=n+1; i++) {
         ya[j][i] = s[j][i] == '*';
         rdp[j][i] = 0;
      }
   }

   go();
   for(int j=0; j<2; j++) {
      for(int i=0; i<=n+1; i++) {
         ldp[j][i] = rdp[j][i];
         rdp[j][i] = 0;
      }
   }
   reverse(ya[0], ya[0] + n + 2);
   reverse(ya[1], ya[1] + n + 2);
   go();
   reverse(rdp[0], rdp[0] + n + 2);
   reverse(rdp[1], rdp[1] + n + 2);
   reverse(flag, flag + n + 2);
   
   int ans = n + n;
   for(int i=1; i<=n; i++) {
      if(!flag[i+1]) {
         ans = min(ans, ldp[0][i]);
         ans = min(ans, ldp[1][i]);
         break;
      }
      ans = min(ans, ldp[0][i] + rdp[1][i+1] + 2);
      ans = min(ans, ldp[1][i] + rdp[0][i+1] + 2);
      ans = min(ans, ldp[0][i] + rdp[0][i+1] + 1);
      ans = min(ans, ldp[1][i] + rdp[1][i+1] + 1);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}