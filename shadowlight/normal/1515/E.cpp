#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mod;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 407;

int dp[N][N];
int C[N][N];
int deg2[N];

void init() {
  C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1];
      add(C[i][j], C[i - 1][j]);
    }
  }

  deg2[0] = 1;
  for (int n = 1; n < N; ++n) {
    deg2[n] = mult(deg2[n - 1], 2);
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n >> mod;

  init();

  for (int a = 1; a <= n; ++a) {
    dp[a + 1][a] = deg2[a - 1];
  }

  for (int len = 2; len <= n - 1; ++len) {
    for (int cnt = 1; cnt <= n; ++cnt) {
      for (int k = 1; k + len + 1 <= n + 1; ++k) {
        int val = mult(dp[len][cnt], mult(C[cnt + k][k], deg2[k - 1]));
        //cout << len << " " << cnt << " " << val << endl;
        add(dp[len + k + 1][cnt + k], val);
      }
    }
  }

  int res = 0;
  for (int t = 1; t <= n; ++t) {
    add(res, dp[n + 1][t]);
  }
  cout << res << "\n";
}