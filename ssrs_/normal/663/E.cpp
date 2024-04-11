#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
vector<long long> fwt(vector<long long> A, int N, bool inv){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < (1 << N); j++){
      if (!(j >> i & 1)){
        long long x = A[j];
        long long y = A[j | (1 << i)];
        A[j] = x + y;
        A[j | (1 << i)] = x - y;
        if (inv){
          A[j] /= 2;
          A[j | (1 << i)] /= 2;
        }
      }
    }
  }
  return A;
}
vector<long long> xor_convolution(vector<long long> A, vector<long long> B, int N){
  A = fwt(A, N, false);
  B = fwt(B, N, false);
  vector<long long> C(1 << N);
  for (int i = 0; i < (1 << N); i++){
    C[i] = A[i] * B[i];
  }
  C = fwt(C, N, true);
  return C;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> A(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }
  vector<int> num(m, 0);
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      num[i] *= 2;
      num[i] += A[j][i] - '0';
    }
  }
  vector<long long> cnt(1 << n, 0);
  for (int i = 0; i < m; i++){
    cnt[num[i]]++;
  }
  vector<long long> cost(1 << n);
  for (int i = 0; i < (1 << n); i++){
    cost[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));
  }
  vector<long long> tmp = xor_convolution(cnt, cost, n);
  long long ans = INF;
  for (int i = 0; i < (1 << n); i++){
    ans = min(ans, tmp[i]);
  }
  cout << ans << endl;
}