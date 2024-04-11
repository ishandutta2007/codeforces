#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
}
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long solve2(int f, int count, int b, long long k){
  if (f == -1 && b == -1){
    return k * modpow(k - 1, count - 1) % MOD;
  }
  if (f == -1 || b == -1){
    return modpow(k - 1, count);
  }
  if (count == -1){
    return 1;
  }
  if (count % 2 == 0){
    long long ans = 0;
    for (int i = count - 1; i >= 1; i -= 2){
      ans += k * modpow(k - 1, i) % MOD;
      ans %= MOD;
    }
    for (int i = count; i >= 2; i -= 2){
      ans = modsub(ans, 2 * modpow(k - 1, i - 1));
      ans %= MOD;
    }
    if (f != b){
      ans++;
      ans %= MOD;
    }
    return ans;
  } else {
    long long ans = 0;
    for (int i = count - 1; i >= 2; i -= 2){
      ans += k * modpow(k - 1, i) % MOD;
      ans %= MOD;
    }
    for (int i = count; i >= 3; i -= 2){
      ans = modsub(ans, 2 * modpow(k - 1, i - 1));
      ans %= MOD;
    }
    if (f != b){
      ans += k - 2;
    } else {
      ans += k - 1;
    }
    return ans % MOD;
  }
}
long long solve(vector<int> A, long long k){
  int N = A.size();
  bool neg = false;
  vector<vector<int>> B(1);
  for (int i = 0; i < N; i++){
    if (A[i] == -1){
      B.back().push_back(A[i]);
      neg = true;
    } else {
      if (B.back().empty()){
        B.back().push_back(A[i]);
      } else if (B.back().back() == -1){
        B.back().push_back(A[i]);
        if (i < N - 1){
          B.push_back(vector<int>());
          B.back().push_back(A[i]);
        }
      } else {
        B.back().back() = A[i];
      }
    }
  }
  if (!neg){
    return 1;
  }
  int C = B.size();
  long long ans = 1;
  for (int i = 0; i < C; i++){
    int count = B[i].size();
    if (B[i].front() != -1){
      count--;
    }
    if (B[i].back() != -1){
      count--;
    }
    int f = B[i].front();
    int b = B[i].back();
    ans *= solve2(f, count, b, k);
    ans %= MOD;
  }
  return ans;
}
int main(){
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> O;
  vector<int> E;
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      E.push_back(a[i]);
    } else {
      O.push_back(a[i]);
    }
  }
  bool flg = false;
  for (int i = 0; i < O.size() - 1; i++){
    if (O[i] != -1 && O[i + 1] != -1 && O[i] == O[i + 1]){
      flg = true;
    }
  }
  for (int i = 0; i < E.size() - 1; i++){
    if (E[i] != -1 && E[i + 1] != -1 && E[i] == E[i + 1]){
      flg = true;
    }
  }
  if (flg){
    cout << 0 << endl;
  } else {
    long long ans1 = solve(O, k);
    long long ans2 = solve(E, k);
    cout << ans1 * ans2 % MOD << endl;
  }
}