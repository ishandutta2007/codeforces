#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz], d[3];

int main() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), d[a[i] % 3]++;

   if(d[0] <= n / 2) {
      puts("0");
      int z = n / 2 - d[0];
      for(int i=0; i<n; i++) {
         if(a[i] % 3 == 0) printf("0");
         else if(z) printf("0"), z--;
         else printf("1");
      } 
   }
   else {
      puts("2");
      int z = d[0] - n / 2;
      for(int i=0; i<n; i++) {
         if(a[i] % 3 != 0) printf("0");
         else if(z) printf("0"), z--;
         else printf("1");
      }
   }
}