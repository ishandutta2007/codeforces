#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];
ll az[sz], ao[sz];

int main() {
   scanf("%s", s);
   int n = strlen(s);
   ll x, y;
   scanf("%lld %lld", &x, &y);   // x = 01, y = 10

   ll atleast = 0, z = 0, o = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '0') {
         atleast += o * y;
         z++;
      }
      if(s[i] == '1') {
         atleast += z * x;
         o++;
      }
   }

   ll nz = 0, no = 0, tz = 0, to = 0, c = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '0') {
         nz++;
      }
      if(s[i] == '1') {
         no++;
      }
      if(s[i] == '?') {
         az[i] = no * y + (o - no) * x;
         ao[i] = nz * x + (z - nz) * y;
         c++;
      }
      tz += az[i];
      to += ao[i];
   }

   ll ans = min(tz, to);

   // 0-1
   ll xz = 0, xo = to, cn = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '?') {
         xz += az[i];
         xo -= ao[i];
         cn++;
         ll now = xz + xo;
         now += cn * (c - cn) * x;
         ans = min(ans, now);
      }
   }

   // 1-0
   xz = tz, xo = 0, cn = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '?') {
         xz -= az[i];
         xo += ao[i];
         cn++;
         ll now = xz + xo;
         now += cn * (c - cn) * y;
         ans = min(ans, now);
      }
   }

   printf("%lld\n", ans + atleast);
}