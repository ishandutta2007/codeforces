#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

void solve() {
   int a[7];
   for(int i=0; i<7; i++) scanf("%d", &a[i]);
   printf("%d %d %d\n", a[0], a[1], a[6] - a[0] - a[1]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}