#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);

   set <int> st;
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         st.insert(a[j] - a[i]);
      }
   }
   printf("%d\n", st.size());
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}