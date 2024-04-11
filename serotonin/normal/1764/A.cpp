#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   printf("1 %d\n", n);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}