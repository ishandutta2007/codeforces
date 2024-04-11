#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, mod;

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

const int N = 507;
int C[N][N];
int f[N];

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

  f[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> mod;
  int nn = n * n;

  init();

  vector<vector<int>> dp(n + 1, vector<int>(nn));
  dp[0][0] = 1;

  for (int cnt = 1; cnt <= n; ++cnt) {
    for (int pos = 0; pos < cnt; ++pos) {
      for (int inversions = 0; inversions + pos < nn; ++inversions) {
        add(dp[cnt][inversions + pos], dp[cnt - 1][inversions]);
      }
    }
  }

  vector <vector<int>> delta_sums(n + 1, vector<int>(n, 0));
  vector <int> total(n + 1);
  total[0] = 1;

  for (int cnt = 1; cnt <= n; ++cnt) {
    int pref = 0;
    for (int inv = 0; inv < nn; ++inv) {
      add(pref, dp[cnt][inv]);
      add(total[cnt], mult(pref, dp[cnt][inv]));
    }

    for (int delta = 0; delta < n; ++delta) {
      if (delta) add(delta_sums[cnt][delta], delta_sums[cnt][delta - 1]);
      
      for (int inv = 0; inv + delta < nn; ++inv) {
        add(delta_sums[cnt][delta], mult(dp[cnt][inv], dp[cnt][inv + delta]));
      }
    }
  }

  int res = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      for (int cnta = 0; cnta <= a; ++cnta) {
        for (int cntb = 0; cntb <= b - a - 1; ++cntb) {
          for (int w = 0; w <= n - b - 1; ++w) {
            int now = mult(C[a][cnta], C[b - a - 1][cntb]);
            now = mult(now, C[n - b - 1][w]);
            now = mult(now, f[cnta + cntb + w]);

            int was = now;

            int rem = n - cnta - cntb - 1 - w;
            int delta = (b - a) - cntb;

            int mlt = total[rem];
            if (delta < 0) {
              add(mlt, delta_sums[rem][-delta - 1]);
            } else {
              add(mlt, -delta_sums[rem][delta]);
            }
            now = mult(now, mlt);


            //cout << a << " " << b << " " << cnta << " " << cntb << " " << w << " " << now << " " << was << endl;
            add(res, now);
          }
        }
      }
    }
  }
  cout << res << "\n";
}