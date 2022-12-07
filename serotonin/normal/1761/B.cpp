#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   if(n == 1) {
      puts("1");
      return;
   }

   set <int> st;
   for(int i=1; i<=n; i++) st.insert(a[i]);

   if(st.size() > 2) {
      printf("%d\n", n);
      return;
   }

   printf("%d\n", n / 2 + 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}