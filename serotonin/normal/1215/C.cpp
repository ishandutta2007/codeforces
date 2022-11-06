#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[sz],t[sz];
vector <int> cx,cy;

int main()
{
   int n;
   cin >> n;
   scanf("%s %s", s, t);

   int x=0, y=0;
   for(int i=0; i<n; i++) {
      if(s[i]=='a') x++;
      if(t[i]=='a') y++;
      if(s[i]!=t[i]) {
         if(s[i]=='a') cx.push_back(i+1);
         else cy.push_back(i+1);
      }
   }

   int z=x-y;
   if(z<0) z=0-z;

   if(z&1) puts("-1");
   else {
      x=cx.size(), y=cy.size();
      int ans=x/2+y/2;
      if(x&1) ans+=2;
      printf("%d\n", ans);

      for(int i=0; i<x; i+=2) {
         if(i+1==x) break;
         printf("%d %d\n", cx[i], cx[i+1]);
      }

      for(int i=0; i<y; i+=2) {
         if(i+1==y) break;
         printf("%d %d\n", cy[i], cy[i+1]);
      }

      if(x&1) {
         printf("%d %d\n", cx.back(), cx.back());
         printf("%d %d\n", cx.back(), cy.back());
      }
   }
}