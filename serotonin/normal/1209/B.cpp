#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e6+5;

int ans[sz];
char s[105];

int main()
{
   int n;
   cin >> n;
   scanf("%s", s);
   for(int i=0; i<n; i++) {
      int d=s[i]-'0';
      int x,y;
      scanf("%d %d", &x, &y);
      for(int k=0; k<y; k++) if(d) ans[k]++;
      while(y<sz) {
         d^=1;
         for(int k=0; k<x && y<sz; k++) {
            if(d) ans[y]++;
            y++;
         }
      }
   }

   int b=0;
   for(int i=0; i<sz; i++) b=max(b,ans[i]);
   cout << b << endl;
}