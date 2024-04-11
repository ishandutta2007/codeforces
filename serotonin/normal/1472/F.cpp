#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz];

void solve() {
   int n;
   scanf("%d %d", &n, &n);
   for(int i=0; i<n; i++) scanf("%d %d", &a[i].y, &a[i].x);
   sort(a, a+n);

   int h = -1, j = 0;
   for(int i=0; i<n; i++) {
      if(j > a[i].x) {
         puts("NO");
         return;
      }
      if(h < 0) {
         j = a[i].x;
         h = ~a[i].y & 1;
      }
      else {
         if((j & 1) ^ (a[i].x & 1)) j ^= 1, h ^= 1;
         if(h ^ (a[i].y & 1)) {
            puts("NO");
            return;
         }
         j = a[i].x + 1;
         h = -1;
      }
   }
   if(h < 0) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}