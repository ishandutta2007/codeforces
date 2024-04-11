#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   map <int,int> mp;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), mp[a[i]]++;
   int cut = 0;
   for(auto [x, y] : mp) cut += y - 1;
   if(cut & 1) cut++;
   printf("%d\n", n - cut);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}