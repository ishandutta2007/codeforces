#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

ll fnc(ll x) {
   return x * (x + 1) / 2;
}

void solve() {
   int n;
   scanf("%d", &n);

   ll rem = 4LL * n * n - 2 * n - fnc(n - 2);

   ll x = rem / n;

   rem %= n;

   // cout << rem << endl;

   vector <int> a;
   for(int i=0; i<n; i++) a.push_back(x + i);
   a[n - 1] = x + 2 * n;
   a[n - 2] += rem;

   assert(a[0] > 0 and a.back() <= 1e9);

   sort(a.begin(), a.end());
   int cnt = unique(a.begin(), a.end()) - a.begin();
   assert(cnt == n);

   for(int x : a) printf("%d ", x); puts("");

   ll sum = 0;
   for(int x : a) sum += x;
   ll R = a.back() - a[0];
   assert(sum == R * R);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}