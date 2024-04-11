#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   
   a[0]--;

   int z = *min_element(a + 1, a + n);
   if(z <= a[0]) puts("Alice");
   else puts("Bob");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}