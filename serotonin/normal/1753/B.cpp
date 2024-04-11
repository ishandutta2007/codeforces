#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5;

int a[sz], c[sz];

int main() {
   int n, x;
   cin >> n >> x;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) c[a[i]]++;
   
   for(int i=1; i<x; i++) {
      if(c[i] % (i + 1)) {
         puts("No");
         return 0;
      }
      c[i + 1] += c[i] / (i + 1);
   }
   puts("Yes");
}