#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long HALF = 500000004;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << 1 << endl;
    } else {
      vector<long long> POW(n);
      POW[0] = 1;
      for (int j = 0; j < n - 1; j++){
        POW[j + 1] = POW[j] * HALF % MOD;
      }
      vector<long long> A(n, 0);
      for (int j = 1; j < n; j++){
        A[j] = POW[j / 2 + 1];
      }
      A[n - 1] *= 2;
      A[n - 1] %= MOD;
      vector<long long> B(n, 0);
      for (int j = n - 1; j >= 0; j--){
        A[j] *= MOD + 1 - B[j];
        A[j] %= MOD;
        if (j > 0){
          B[j - 1] += B[j];
          B[j - 1] %= MOD;
        }
        if (j >= 3){
          B[(j - 1) / 2] += A[j];
          B[(j - 1) / 2] %= MOD;
        }
      }
      for (int j = 0; j < n; j++){
        cout << A[j] << "\n";
      }
    }
  }
}