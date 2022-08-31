#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
int MAX = 300000;
vector<long long> gcd_convolution(vector<long long> A, vector<long long> B){
  int N = A.size();
  for (int i = 1; i < N; i++){
    for (int j = i * 2; j < N; j += i){
      A[i] += A[j];
      B[i] += B[j];
    }
  }
  vector<long long> C(N);
  for (int i = 0; i < N; i++){
    C[i] = A[i] * B[i];
  }
  for (int i = N - 1; i >= 1; i--){
    for (int j = i * 2; j < N; j += i){
      C[i] -= C[j];
    }
  }
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
  int g = 0;
  for (int i = 0; i < n; i++){
    g = gcd(g, a[i]);
  }
  if (g != 1){
    cout << -1 << endl;
  } else {
    //sequence
    vector<long long> A(MAX + 1, 0);
    for (int i = 0; i < n; i++){
      if (A[a[i]] == 0){
        A[a[i]] = 1;
      }
    }
    vector<long long> B = A;
    int cnt = 1;
    while (1){
      if (B[1] != 0){
        break;
      }
      B = gcd_convolution(A, B);
      cnt++;
    }
    cout << cnt << endl;
  }
}