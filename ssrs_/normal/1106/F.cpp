#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long B = 31595;
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
vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				ans[i][k] += A[i][j] * B[j][k];
				ans[i][k] %= MOD - 1;
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
long long modlog(long long a, long long b){
  //a^x=b
  long long biginv = modinv(modpow(a, B));
  map<long long, int> mp;
  long long tmp = 1;
  for (int i = 0; i < B; i++){
    mp[tmp] = i;
    tmp *= a;
    tmp %= MOD;
  }
  int cnt = 0;
  while (true){
    if (mp.count(b)){
      return cnt * B + mp[b];
    }
    b *= biginv;
    b %= MOD;
    cnt++;
  }
}
pair<long long, long long> ext_gcd(int a, int b){
  if (a > b){
    pair<long long, long long> S = ext_gcd(b, a);
    return make_pair(S.second, S.first);
  }
  if (a == 1){
    return make_pair(1, 0);
  } else {
    pair<long long, long long> S = ext_gcd(b % a, a);
    return make_pair(S.second - b / a * S.first, S.first);
  }
}
long long composite_modinv(long long a, long long mod){
  long long tmp = ext_gcd(a, mod).first;
  return (tmp % mod + mod) % mod;
}
int main(){
  int k;
  cin >> k;
  vector<long long> b(k);
  for (int i = 0; i < k; i++){
    cin >> b[i];
  }
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> mat(k, vector<long long>(k, 0));
  for (int i = 0; i < k - 1; i++){
    mat[i][i + 1] = 1;
  }
  for (int i = 0; i < k; i++){
    mat[k - 1][i] = b[k - 1 - i];
  }
  mat = matexp(mat, n - k);
  long long a = mat[k - 1][k - 1];
  long long c = modlog(3, m);
  long long mod = MOD - 1;
  //ab=c mod p-1
  int g = __gcd(__gcd(a, c), mod);
  a /= g;
  c /= g;
  mod /= g;
  if (__gcd(a, mod) > 1){
    cout << -1 << endl;
  } else if (a == 0){
    if (c == 0){
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    long long b = composite_modinv(a, mod) * c % mod;
    cout << modpow(3, b) << endl;
  }
}