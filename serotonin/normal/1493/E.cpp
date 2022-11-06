#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int n;
char a[sz], b[sz];

bool cmp() {
   for(int i=0; i<n; i++) {
      if(a[i] != b[i]) return a[i] < b[i];
   }
   return 1;
}

bool add() {
   int i = n - 1;
   while(i >= 0 and a[i] == '1') a[i--] = '0';
   if(i < 0) return 0;
   a[i] = '1';
   return cmp();
}

int main() {
   cin >> n;
   scanf("%s %s", a, b);
   if(n == 1) {
      puts(b);
      return 0;
   }
   if(a[0] == '1') {
      if(b[n-1] == '1') puts(b);
      else {
         bool yes = 0;
         if(b[n-2] == '0') {
            for(int j=0; j<4; j++) {
               if(a[n-1] == '0' and a[n-2] == '1') yes = 1;
               if(!add()) break;
            }
         }
         else {
            for(int j=0; j<4; j++) {
               if(a[n-1] == '0' and a[n-2] == '0') yes = 1;
               if(!add()) break;
            }
         }
         if(yes) b[n-1] = '1';
         puts(b);
      }
   }
   else for(int i=0; i<n; i++) printf("1");
}