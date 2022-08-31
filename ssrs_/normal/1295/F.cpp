#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				ans[i][k] += A[i][j] * B[j][k];
				ans[i][k] %= MOD;
			}
		}
	}
	return ans;
}
vector<vector<long long>> matexp(vector<vector<long long>> A, long long b){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		ans[i][i] = 1;
	}
	while (b > 0){
		if (b % 2 == 1){
			ans = matmul(ans, A);
		}
		A = matmul(A, A);
		b /= 2;
	}
	return ans;
}
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
int main(){
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    r[i]++;
  }
  vector<pair<int, int>> c;
  for (int i = 0; i < n; i++){
    c.push_back(make_pair(l[i], i));
    c.push_back(make_pair(r[i], i));
  }
  sort(c.begin(), c.end(), greater<pair<int, int>>());
  vector<vector<long long>> mat(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; i++){
    mat[i][i] = 1;
  }
  vector<bool> used(n, false);
  for (int i = 0; i < n * 2 - 1; i++){
    used[c[i].second] = !used[c[i].second];
    vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0));
    for (int j = 0; j <= n; j++){
      a[j][j] = 1;
    }
    for (int j = 0; j < n; j++){
      if (used[j]){
        a[j][j + 1] = 1;
      }
    }
    for (int j = n - 2; j >= 0; j--){
      for (int k = j + 2; k <= n; k++){
        if (a[j + 1][k] == 1 && a[j][k - 1]){
          a[j][k] = 1;
        }
      }
    }
    a = matexp(a, c[i].first - c[i + 1].first);
    mat = matmul(mat, a);
  }
  long long ans = mat[0][n];
  for (int i = 0; i < n; i++){
    ans *= modinv(r[i] - l[i]);
    ans %= MOD;
  }
  cout << ans << endl;
}