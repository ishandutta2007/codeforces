#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   int x = n - k + 1;
   for(int i=1; i<=k-x; i++) printf("%d ", i);
   for(int i=k, j=0; j<x; i--, j++) printf("%d ", i);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}