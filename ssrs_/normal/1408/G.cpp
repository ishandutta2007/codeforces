#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
struct unionfind{
  vector<int> p;
  vector<int> sz;
  vector<int> edges;
  vector<int> id;
  vector<vector<int>> ch;
  int next;
  unionfind(int n){
    p = vector<int>(n, -1);
    sz = vector<int>(n, 1);
    edges = vector<int>(n, 0);
    id = vector<int>(n);
    ch = vector<vector<int>>(n);
    for (int i = 0; i < n; i++){
      id[i] = i;
    }
    next = n;
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  int size(int x){
    return sz[root(x)];
  }
  vector<int> add_edge(int u, int v){
    u = root(u);
    v = root(v);
    if (u != v){
      p[u] = v;
      sz[v] += sz[u];
      edges[v] += edges[u];
      for (int x : ch[u]){
        ch[v].push_back(x);
      }
      if (id[u] != -1){
        ch[v].push_back(id[u]);
      }
      if (id[v] != -1){
        ch[v].push_back(id[v]);
      }
      id[v] = -1;
    }
    edges[v]++;
    if (edges[v] == sz[v] * (sz[v] - 1) / 2){
      //cout << "v = " << v << ", sz = " << sz[v] << endl;
      id[v] = next;
      next++;
      vector<int> ans = ch[v];
      ch[v].clear();
      return ans;
    } else {
      return vector<int>(0);
    }
  }
};
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
vector<long long> ntt(vector<long long> A, bool inv){
	int N = A.size();
	long long r = 3;
	if (inv){
		r = modinv(r);
	}
	vector<long long> B(N);
	for (int i = N / 2; i > 0; i /= 2){
		long long z = modpow(r, (MOD - 1) / (N / i));
		long long z2 = 1;
		for (int j = 0; j < N; j += i * 2){
			for (int k = 0; k < i; k++){
				A[i + j + k] *= z2;
				A[i + j + k] %= MOD;
				B[j / 2 + k] = (A[j + k] + A[i + j + k]) % MOD;
				B[N / 2 + j / 2 + k] = (A[j + k] - A[i + j + k] + MOD) % MOD;
			}
			z2 = z2 * z % MOD;
		}
		swap(A, B);
	}
	if (inv){
		int Ninv = modinv(N);
		for (int i = 0; i < N; i++){
			A[i] = A[i] * Ninv % MOD;
		}
	}
	return A;
}
vector<long long> convolution(vector<long long> A, vector<long long> B, int d = -1){
	int deg = A.size() + B.size() - 1;
	int N = 1;
	while (N < deg){
		N *= 2;
	}
	A.resize(N);
	B.resize(N);
	A = ntt(A, false);
	B = ntt(B, false);
	vector<long long> ans(N);
	for (int i = 0; i < N; i++){
		ans[i] = A[i] * B[i] % MOD;
	}
	ans = ntt(ans, true);
	if (d != -1){
		deg = d;
	}
	ans.resize(deg);
	return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  vector<tuple<int, int, int>> E;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      E.push_back(make_tuple(a[i][j], i, j));
    }
  }
  sort(E.begin(), E.end());
  int cnt = E.size();
  unionfind UF(n);
  vector<vector<int>> ch(n);
  for (int i = 0; i < cnt; i++){
    int u = get<1>(E[i]);
    int v = get<2>(E[i]);
    vector<int> A = UF.add_edge(u, v);
    if (!A.empty()){
      ch.push_back(A);
    }
  }
  int V = ch.size();
  /*
  cout << V << endl;
  for (int i = 0; i < V; i++){
    cout << "i = " << i << ":";
    for (int j : ch[i]){
      cout << ' ' << j;
    }
    cout << endl;
  }
  */
  vector<vector<long long>> dp(V);
  for (int i = 0; i < n; i++){
    dp[i] = vector<long long>(2, 0);
    dp[i][1] = 1;
  }
  for (int i = n; i < V; i++){
    dp[i] = vector<long long>(1, 1);
    for (int j : ch[i]){
      dp[i] = convolution(dp[i], dp[j]);
    }
    dp[i][1] = 1;
  }
  int sz = dp[V - 1].size();
  for (int i = 1; i < sz; i++){
    cout << dp[V - 1][i] << ' ';
  }
  cout << endl;
}