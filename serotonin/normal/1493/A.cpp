#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   vector <int> a;
   for(int i=(k+1)/2; i<=n; i++) if(i != k) a.push_back(i);
   printf("%d\n", a.size());
   for(int x : a) printf("%d ", x);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}