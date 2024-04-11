#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7, mod = 998244353;

int dp[sz];

int main() {
   for(int i=2; i<sz; i++) {
      for(int j=i; j<sz; j+=i) {
         dp[j]++;
      }
   }

   dp[0] = 1;
   int sum = 1;
   for(int i=1; i<sz; i++) {
      dp[i] += sum;
      if(dp[i] >= mod) dp[i] -= mod;
      sum += dp[i];
      if(sum >= mod) sum -= mod;
   }

   int n;
   cin >> n;
   cout << dp[n];
}