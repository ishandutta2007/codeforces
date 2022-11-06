#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[sz];
int dp[sz][10];

int fnc(int i, int m) {
   if(!i) return 0;
   int &w = dp[i][m];
   if(w >= 0) return w;
   int x = m % 3; m /= 3;
   w = s[i] != 'a' + x;

   int a[3] = {};
   a[x] = a[m] = 1;
   int j = 0; while(a[j]) j++;
   m += j * 3;
   w += fnc(i - 1, m);
   return w;
}

int main() {
   int n, q;
   cin >> n >> q;
   scanf("%s", s + 1);

   memset(dp, -1, sizeof(dp));

   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if(l == r) puts("0");
      else {
         l--;
         int ans = r - l, cut = ans % 3;
         for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
               if(i == j) continue;

               int a[3] = {};
               a[i] = a[j] = 1;
               int k = 0;
               while(a[k]) k++;

               int c[] = {i, j, k};
               int x = c[cut], y = c[(cut + 1) % 3];
               int bad = y * 3 + x;

               int m = j * 3 + i;
               int now = fnc(r, m) - fnc(l, bad);

//               printf("%d %d : %d %d\n", i, j, fnc(r, m), fnc(l, bad));
//               cout << x << endl;

               ans = min(ans, now);
            }
         }
         printf("%d\n", ans);
      }
   }
}