#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 2e9;

vector <ll> a;

void solve() {
   int n;
   scanf("%d", &n);
   printf("%d\n", upper_bound(a.begin(), a.end(), n) - a.begin());
}

int main() {
   for(int i=1; i<10; i++) {
      ll v = 0;
      while(v < sz) {
         v = v * 10 + i;
         a.push_back(v);
      }
   }
   sort(a.begin(), a.end());
   int t;
   cin >> t;
   while(t--) solve();
}