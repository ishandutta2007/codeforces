#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

char s[sz];

int main()
{
   scanf("%s", s);
   puts("Mike");
   char x=s[0];
   for(int i=1; s[i]; i++) {
      if(x<s[i]) puts("Ann");
      else puts("Mike");
      x=min(x,s[i]);
   }
}