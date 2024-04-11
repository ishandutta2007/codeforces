#include <bits/stdc++.h>
using namespace std;
const int SQRT = 270;
const long long MOD = 1000000007;
int gcd(int x, int y){
  if (y == 0){
    return x;
  } else {
    return gcd(y, x % y);
  }
}
vector<long long> f(vector<long long> A){
  int N = A.size();
  vector<bool> prime(N, true);
  for (int i = 2; i < N; i++){
    if (prime[i]){
      for (int j = (N - 1) / i; j >= 1; j--){
        prime[i * j] = false;
        A[j] += A[i * j];
        if (A[j] >= MOD){
          A[j] -= MOD;
        }
      }  
    }
  }
  return A;
}
vector<long long> g(vector<long long> A){
  int N = A.size();
  vector<bool> prime(N, true);
  for (int i = 2; i < N; i++){
    if (prime[i]){
      for (int j = 1; j * i < N; j++){
        prime[i * j] = false;
        A[j] += MOD - A[i * j];
        if (A[j] >= MOD){
          A[j] -= MOD;
        }
      }
    }
  }
  return A;
}
vector<long long> gcd_convolution(vector<long long> A){
  int N = A.size();
  A = f(A);
  vector<long long> C(N);
  for (int i = 0; i < N; i++){
    C[i] = A[i] * A[i] % MOD;
  }
  C = g(C);
  return C;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> m(n + 1, 0);
  for (int i = 1; i <= n; i++){
    m[i] += i;
  }
  for (int i = 1; i <= n; i++){
    for (int j = i * 2; j <= n; j += i){
      m[j] -= m[i];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++){
    vector<int> b;
    for (int j = i - 1; j < n; j += i){
      b.push_back(a[j]);
    }
    int cnt = b.size();
    long long sum = 0;
    if (cnt < SQRT){
      for (int j = i - 1; j < n; j += i){
        sum += a[j];
        for (int k = j + i; k < n; k += i){
          sum += gcd(a[j], a[k]) * 2;
        }
      }
    } else {
      vector<long long> f(100001, 0);
      for (int j = i - 1; j < n; j += i){
        f[a[j]]++;
      }
      f = gcd_convolution(f);
      for (int j = 1; j <= 100000; j++){
        sum += f[j] * j;
        sum %= MOD;
      }
    }
    sum %= MOD;
    sum *= m[i];
    sum %= MOD;
    ans += sum;
  }
  ans %= MOD;
  cout << ans << endl;
}