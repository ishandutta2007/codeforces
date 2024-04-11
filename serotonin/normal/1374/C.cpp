#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char s[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n, ans = 0;
      scanf("%d %s", &n, s);
      for(int i=0, j=0; i<n; i++) {
         if(s[i] == '(') j++;
         else j--;
         if(j < 0) ans++, j = 0;
      }
      printf("%d\n", ans);
   }
}