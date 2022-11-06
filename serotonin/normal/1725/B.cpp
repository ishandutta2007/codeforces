#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main() {
   int n, d;
   cin >> n >> d;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);

   int ans = 0;
   for(int i=0, j=n-1; i<=j; j--) {
      int now = a[j];
      while(i < j and now <= d) now += a[j], i++;
      ans += now > d;
   }
   cout << ans;
}