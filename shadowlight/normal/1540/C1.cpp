#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

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

const int MAXN = 1e4 + 7;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector <int> c(n);
  vector <int> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }

  int q;
  cin >> q;

  int x;
  cin >> x;

  vector <int> dp(MAXN, 0);
  dp[0] = 1;

  vector <int> elem_down(n, 0);
  int prefix = 0;
  for (int i = 0; i < n; ++i) {
    elem_down[i] = x + prefix;
    prefix += b[i];
  }

  vector <ll> prefix_down(n, 0);
  prefix_down[0] = elem_down[0];
  
  for (int i = 1; i < n; ++i) {
    prefix_down[i] = prefix_down[i - 1] + elem_down[i];
  }


  for (int a = 0; a < n; ++a) {
    vector<int> dpn(MAXN, 0);
    for (int i = 0; i < MAXN; ++i) {
      if (!dp[i]) continue;
      for (int now = 0; now <= c[a]; ++now) {
        if (i + now < prefix_down[a]) continue;
        add(dpn[i + now], dp[i]);
      }
    }
    dp = dpn;
  }

  int res = 0;
  for (int i = 0; i < MAXN; ++i) {
    add(res, dp[i]);
  }
  cout << res << "\n";
}