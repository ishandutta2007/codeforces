#include <cstdio>
#include <iostream>
using namespace std;

int g(int a, int b) {
  if (a == 0) return b;
  return g(b % a, a);
}

const int MAXN = 200100;
int dp[MAXN];
int main() {
  string s;
  int n;
  cin >> n;
  cin >> s;

  int ans = 0;
  for(int k = 1; k <= n; ++k) {
    if (n % k == 0) {
      dp[k] = 1;
      for(int i = 0; i < k; ++i) {
        int par = 0;
        for(int j = i; j < n; j += k) {
          if (s[j] == '1') {
            par += 1;
          }
        }
        if (par % 2 == 1) {
          dp[k] = 0;
        }
      }
      ans += dp[k];
    } else {
      int p = g(k, n);
      ans += dp[p];
    }
  }

  cout << ans << "\n";
}