#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   map <int,int> mp;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), mp[a[i]] = 1;
   int g = 1;
   for(auto &[x, c] : mp) c = ++g;
   for(int i=0; i<n; i++) a[i] = mp[a[i]];
   int cnt = 1;
   for(int i=1; i<n; i++) cnt += a[i] != a[i-1] + 1;
   puts(cnt <= k ? "YES" : "NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}