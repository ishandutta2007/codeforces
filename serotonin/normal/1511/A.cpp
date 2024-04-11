#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int cnt = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), cnt += a[i] == 2;
   printf("%d\n", n - cnt);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}