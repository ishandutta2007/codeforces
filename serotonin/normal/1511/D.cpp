#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[30];

int main() {
   for(int i=0; i<30; i++) s[i] = 'a' + i;

   int n, k;
   cin >> n >> k;
   string ans;
   for(int i=0; i<k; i++) {
      ans += s[i];
      for(int j=i+1; j<k; j++) ans += s[i], ans += s[j];
   }
   string res;
   while(res.size() < n) res += ans;
   cout << res.substr(0, n);
}