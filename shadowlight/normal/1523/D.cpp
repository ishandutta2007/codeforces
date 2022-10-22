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

const int ITERATIONS = 30;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  srand(1488);

  int n, m, p;
  cin >> n >> m >> p;

  vector<string> edges(n);
  for (int i = 0; i < n; ++i) {
    cin >> edges[i];
  }

  int need = (n + 1) / 2;

  int res = 0;
  ll resw = 0;

  for (int it = 0; it < ITERATIONS; ++it) {
    random_shuffle(all(edges));
    vector <int> positions;
    for (int i = 0; i < m; ++i) {
      if (edges[0][i] == '1') {
        positions.pb(i);
      }
    }

    int cnt = positions.size();
    
    vector<int> dp((1 << cnt), 0);
    
    for (int i = 0; i < n; ++i) {
      int mask = 0;
      for (int j = 0; j < cnt; ++j) {
        if (edges[i][positions[j]] == '1') {
          mask += (1 << j);
        }
      }

      dp[mask] += 1;
      //cout << edges[i] << " " << bitset<4>(mask) << "\n";
    }

    for (int mask = 0; mask < (1 << cnt); ++mask) {
      int maskn = mask;

      while (maskn) {
        maskn = (maskn - 1) & mask;
        dp[maskn] += dp[mask];
      }
    }



    for (int mask = 0; mask < (1 << cnt); ++mask) {
      if (dp[mask] >= need && __builtin_popcount(mask) >= res) {
        res = __builtin_popcount(mask);
        resw = 0;
        for (int i = 0; i < cnt; ++i) {
          if (mask & (1 << i)) {
            resw += (1LL << positions[i]);
          }
        }
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    if (resw & (1LL << i)) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << "\n";
}