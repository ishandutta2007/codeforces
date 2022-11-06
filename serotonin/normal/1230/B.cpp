#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[sz];

int main()
{
   int n,k;
   cin >> n >> k;
   scanf("%s", s);
   if(!k) puts(s);
   else {
      if(s[0]!='1') k--, s[0]='1';
      for(int i=1; i<n; i++) {
         if(!k) break;
         if(s[i]!='0') s[i]='0', k--;
      }
      if(n>1) s[0]='1';
      else s[0]='0';
      puts(s);
   }
}