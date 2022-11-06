#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e9+7;

set <int> st;

void solve() {
   int n;
   scanf("%d", &n);
   if(n % 2 == 0 and st.count(n / 2)) puts("YES");
   else if(n % 4 == 0 and st.count(n / 4)) puts("YES");
   else puts("NO");
}

int main() {
   for(int i=1; i*i<sz; i++) st.insert(i*i);
   int t;
   cin >> t;
   while(t--) solve();
}