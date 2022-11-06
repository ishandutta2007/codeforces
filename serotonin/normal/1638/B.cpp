#include<bits/extc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   vector <int> odd, eve;
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      if(a[i] & 1) odd.push_back(a[i]);
      else eve.push_back(a[i]);
   }
   for(int j=1; j<odd.size(); j++) {
      if(odd[j] < odd[j-1]) {
         puts("No");
         return;
      }
   }
   for(int j=1; j<eve.size(); j++) {
      if(eve[j] < eve[j-1]) {
         puts("No");
         return;
      }
   }
   puts("Yes");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}