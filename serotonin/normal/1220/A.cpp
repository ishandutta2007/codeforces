#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

char s[sz];
int a[2];

int main()
{
   int n;
   cin >> n;
   scanf("%s", s);
   for(int i=0; i<n; i++) {
      if(s[i]=='n') a[0]++;
      if(s[i]=='z') a[1]++;
   }

   while(a[0]--) {
      printf("1 ");
   }
   while(a[1]--) {
      printf("0 ");
   }
}