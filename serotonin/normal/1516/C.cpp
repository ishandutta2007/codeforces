#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];
bool yes[sz];

int main() {
   int n, sum = 0;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]), sum += a[i];
   if(sum & 1) {
      puts("0");
      return 0;
   }

   yes[0] = 1;
   for(int i=0; i<n; i++) {
      for(int j=sz-1; j>=0; j--) {
         if(yes[j] and j + a[i] < sz) yes[j + a[i]] = 1;
      }
   }
   if(!yes[sum >> 1]) {
      puts("0");
      return 0;
   }

   int g = a[0];
   for(int i=1; i<n; i++) g = __gcd(g, a[i]);
   for(int i=0; i<n; i++) a[i] /= g;
   for(int i=0; i<n; i++) if(a[i] & 1) {
      cout << 1 << endl << i + 1;
      return 0;
   }
}