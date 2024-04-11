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
long long gauss_jordan(vector<vector<long long>> &A, vector<long long> &b){
  int N = A.size();
  vector<vector<long long>> B(N, vector<long long>(N + 1));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      B[i][j] = A[i][j];
    }
    B[i][N] = b[i];
  }
  for (int i = 0; i < N; i++){
    int pivot = i;
    for (int j = i; j < N; j++){
      if (B[j][i] > B[pivot][i]){
        pivot = j;
      }
    }
    swap(B[i], B[pivot]);
    long long tmp = modinv(B[i][i]);
    for (int j = i + 1; j <= N; j++){
      B[i][j] *= tmp;
      B[i][j] %= MOD;
    }
    for (int j = 0; j < N; j++){
      if (i != j){
        for (int k = i + 1; k <= N; k++){
          B[j][k] -= B[j][i] * B[i][k] % MOD;
          if (B[j][k] < 0){
            B[j][k] += MOD;
          }
        }
      }
    }
  }
  return B[0][N];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<int> d(n, 0);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      d[j]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (d[i] == 0){
      Q.push(i);
    }
  }
  vector<int> b;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : E[v]){
      d[w]--;
      if (d[w] == 0){
        Q.push(w);
      }
    }
  }
  vector<int> grundy(n, 0);
  int mx = 0;
  for (int i = n - 1; i >= 0; i--){
    unordered_set<int> st;
    for (int j : E[b[i]]){
      st.insert(grundy[j]);
    }
    while (st.count(grundy[b[i]])){
      grundy[b[i]]++;
    }
    mx = max(mx, grundy[b[i]]);
  }
  int mx2 = 1;
  while (mx2 <= mx){
    mx2 *= 2;
  }
  assert(mx2 <= 512);
  vector<vector<long long>> ma(mx2, vector<long long>(mx2, 0));
  vector<long long> p(mx2, 0);
  for (int i = 0; i < mx2; i++){
    ma[i][i] = 1;
  }
  long long pp = modinv(n + 1);
  for (int i = 0; i < mx2; i++){
    for (int j = 0; j < n; j++){
      ma[i][i ^ grundy[j]] -= pp;
      if (ma[i][i ^ grundy[j]] < 0){
        ma[i][i ^ grundy[j]] += MOD;
      }
    }
  }
  p[0] = pp;
  long long ans = 1 - gauss_jordan(ma, p);
  if (ans < 0){
    ans += MOD;
  }
  cout << ans << endl;
}