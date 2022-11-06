#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   if(a[0] < 0) {
      puts("NO");
      return;
   }
   puts("YES");
   puts("300");
   for(int i=0; i<300; i++) printf("%d ", i);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}