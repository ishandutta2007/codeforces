#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e4+5;

char a[sz], b[sz];
int la, lb, cut[sz], dp[sz][2];

inline int fnc(int x, int y, int f = 0) {
   if(x == la) return y ^ lb ? sz : 0;
   return dp[x][f];
}

int main()
{
   scanf("%s %s", a, b);
   la = strlen(a), lb = strlen(b);

   for(int i=0; i<la; i++) {
      cut[i] = -1;
      if(a[i] == '.') continue;
      for(int j=i, k=0; j<la; j++) {
         if(a[j] == '.') k--;
         else k++;
         if(!k) {
            cut[i] = j+1;
            break;
         }
      }
   }

   for(int j=lb; j>=0; j--) {
      for(int i=la-1; i>=0; i--) {
         int &res = dp[i][0] = sz;
         if(j < lb && a[i] == b[j]) res = min(res, fnc(i+1, j+1, 1));
         res = min(res, 1 + fnc(i+1, j));
         if(cut[i] >= 0) res = min(res, fnc(cut[i], j));
      }
      for(int i=la-1; i>=0; i--) dp[i][1] = dp[i][0];
   }

   cout << dp[0][0];
}