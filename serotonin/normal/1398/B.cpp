#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

char s[sz];

void solve() {
   scanf("%s", s);
   vector <int> a;
   int j=0;
   for(int i=0; s[i]; i++) {
      if(s[i] == '1') j++;
      else {
         if(j) a.push_back(j);
         j = 0;
      }
   }
   if(j) a.push_back(j);
   sort(a.begin(), a.end(), greater<int>());

   int ans = 0;
   for(int i=0; i<a.size(); i+=2) ans += a[i];
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}