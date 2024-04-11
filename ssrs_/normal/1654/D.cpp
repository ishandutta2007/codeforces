#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
void dfs1(vector<vector<tuple<int, int, int>>> &E, vector<int> &pf, vector<bool> &used, vector<int> &curr, vector<int> &mn, int v){
  for (auto e : E[v]){
    int x = get<0>(e);
    int y = get<1>(e);
    int w = get<2>(e);
    if (!used[w]){
      used[w] = true;
      int x2 = x;
      while (x2 > 1){
        curr[pf[x2]]--;
        mn[pf[x2]] = min(mn[pf[x2]], curr[pf[x2]]);
        x2 /= pf[x2];
      }
      int y2 = y;
      while (y2 > 1){
        curr[pf[y2]]++;
        y2 /= pf[y2];
      }
      dfs1(E, pf, used, curr, mn, w);
      int x3 = x;
      while (x3 > 1){
        curr[pf[x3]]++;
        x3 /= pf[x3];
      }
      int y3 = y;
      while (y3 > 1){
        curr[pf[y3]]--;
        y3 /= pf[y3];
      }
    }
  }
}
void dfs2(vector<vector<tuple<int, int, int>>> &E, vector<bool> &used, long long &ans, long long X, int v){
  ans += X;
  ans %= MOD;
  for (auto e : E[v]){
    int x = get<0>(e);
    int y = get<1>(e);
    int w = get<2>(e);
    if (!used[w]){
      used[w] = true;
      long long X2 = X * modinv(x) % MOD * y % MOD;
      dfs2(E, used, ans, X2, w);
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<tuple<int, int, int>>> E(n);
    for (int j = 0; j < n - 1; j++){
      int i2, j2, x, y;
      cin >> i2 >> j2 >> x >> y;
      i2--;
      j2--;
      int g = gcd(x, y);
      x /= g;
      y /= g;
      E[i2].push_back(make_tuple(x, y, j2));
      E[j2].push_back(make_tuple(y, x, i2));
    }
    vector<int> pf(n + 1, -1);
    for (int j = 2; j <= n; j++){
      if (pf[j] == -1){
        for (int k = j; k <= n; k += j){
          pf[k] = j;
        }
      }
    }
    vector<bool> used(n, false);
    used[0] = true;
    vector<int> curr(n + 1, 0);
    vector<int> mn(n + 1, 0);
    dfs1(E, pf, used, curr, mn, 0);
    long long X = 1;
    for (int j = 2; j <= n; j++){
      if (pf[j] == j){
        for (int k = 0; k < -mn[j]; k++){
          X *= j;
          X %= MOD;
        }
      }
    }
    vector<bool> used2(n, false);
    used2[0] = true;
    long long ans = 0;
    dfs2(E, used2, ans, X, 0);
    cout << ans << endl;
  }
}