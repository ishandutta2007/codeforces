#include <bits/stdc++.h>
 
using namespace std;
 
using ld = long double;
using u64 = long long;

u64 M=1ll<<50;

struct u128 {
  u64 lo,hi;
  ld todb() {
  	return (ld)M*hi+lo;
  }
};
u128 operator + (const u128 &a,const u128 &b) {
	return u128{(a.lo+b.lo)&(M-1),a.hi+b.hi+((a.lo+b.lo)>>50)};
}
u128 operator - (const u128 &a,const u128 &b) {
	if (a.lo>=b.lo) return u128{a.lo-b.lo,a.hi-b.hi};
	else return u128{a.lo-b.lo+M,a.hi-b.hi-1};
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  if (*max_element(a.begin(), a.end()) == x) {
    cout << x * n << "\n";
    return 0;
  }
  vector<vector<u128>> c(n + 1, vector<u128>(n + 1));
  for (int i = 0; i <= n; ++i) {
    c[i][0]=u128{1,0};
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  vector<ld> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + ((ld) n / (n - i) + 1) * x / 2;
  }
  vector<vector<u128>> dp(n + 1, vector<u128>(s + 1));
  dp[0][0] = u128{1,0};
  for (int w : a) {
    for (int i = n; i; --i) {
      for (int j = s; j >= w; --j) {
       dp[i][j] = dp[i][j] + dp[i - 1][j - w];
      }
    } 
  }
  ld ans = 0;
  for (int w : a) {
    vector<vector<u128>> new_dp = dp;
    for (int i = 1; i <= n; ++i) {
      for (int j = w; j <= s; ++j) {
        new_dp[i][j] = new_dp[i][j] - new_dp[i - 1][j - w];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= s - w; ++j) {
        ld cost = ((ld) n / (i + 1) + 1) * x / 2;
        ld ave = (ld) (j + w) / (i + 1);
        if (ave > cost) {
          ld cost2 = !i ? 0 : ((ld) n / i + 1) * x / 2;
          ld ave2 = !i ? 0 : (ld) j / i;
          if (ave2 <= cost2) {
            ans += new_dp[i][j].todb() / c[n][i + 1].todb() / (i + 1) * (sum[n - i] + j);
          }
        }
      }
    }
  }
  cout << fixed << setprecision(20) << ans << "\n";
  return 0;
}