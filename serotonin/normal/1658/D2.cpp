#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

void solve() {
   int l, r;
   scanf("%d %d", &l, &r);
   int n = r - l + 1;
   vector <int> a(n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a.begin(), a.end());

   ll b[20] = {}, tot = 0;
   for(int i=0; i<n; i++) tot += a[i];
   for(int i=l; i<=r; i++) {
      for(int j=0; j<20; j++) if(i & 1 << j) b[j]++;
   }

   vector <int> idk;
   for(int i=0; i<n; i++) {
      int x = a[i] ^ l;
      ll sum = 0;
      for(int j=0; j<20; j++) {
         if(x & 1 << j) {
            sum += (1 << j) * (n - b[j]);
         }
         else {
            sum += (1 << j) * b[j];
         }
      }
      if(sum == tot) idk.push_back(x);
   }
   
   for(int x : idk) {
      vector <int> b(n);
      for(int i=l; i<=r; i++) b[i-l] = i ^ x;
      sort(b.begin(), b.end());
      if(a == b) {
         printf("%d\n", x);
         return;
      }
   }
   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}