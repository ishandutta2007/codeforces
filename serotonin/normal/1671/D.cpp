#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   ll sum = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=1; i<n; i++) sum += abs(a[i] - a[i-1]);
   
   int big = *max_element(a, a+n);

   int one = min(a[0] - 1, a[n-1] - 1);
   for(int i=1; i<n-1; i++) one = min(one, 2 * a[i] - 2);

   int em = min(abs(a[0] - m), abs(a[n-1] - m));
   for(int i=1; i<n-1; i++) em = min(em, 2 * abs(a[i] - m));

   if(m > big) sum += em;
   printf("%lld\n", sum + one);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}