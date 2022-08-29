#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, MOD;
  cin >> n >> q >> MOD;
  vector<long long> A(n);
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  vector<long long> B(n);
  for (int i = 0; i < n; i++){
    cin >> B[i];
  }
  vector<long long> imosA(n + 2, 0), imosB(n + 2, 0);
  for (int i = 0; i < n; i++){
    imosA[i] += A[i];
    imosA[i + 1] += MOD - A[i];
    imosA[i + 2] += MOD - A[i];
    imosB[i] += B[i];
    imosB[i + 1] += MOD - B[i];
    imosB[i + 2] += MOD - B[i];
  }
  vector<long long> F(n + 1);
  F[0] = 1;
  F[1] = 1;
  for (int i = 2; i <= n; i++){
    F[i] = (F[i - 1] + F[i - 2]) % MOD;
  }
  for (int i = 0; i < n + 2; i++){
    imosA[i] %= MOD;
    imosB[i] %= MOD;
  }
  int cnt = 0;
  for (int i = 0; i < n + 2; i++){
    if (imosA[i] != imosB[i]){
      cnt++;
    }
  }
  for (int i = 0; i < q; i++){
    char c;
    int l, r;
    cin >> c >> l >> r;
    l--;
    if (imosA[l] != imosB[l]){
      cnt--;
    }
    if (imosA[r] != imosB[r]){
      cnt--;
    }
    if (imosA[r + 1] != imosB[r + 1]){
      cnt--;
    }
    if (c == 'A'){
      imosA[l]++;
      imosA[r] += MOD - F[r - l];
      imosA[r + 1] += MOD - F[r - l - 1];
      imosA[l] %= MOD;
      imosA[r] %= MOD;
      imosA[r + 1] %= MOD;
    }
    if (c == 'B'){
      imosB[l]++;
      imosB[r] += MOD - F[r - l];
      imosB[r + 1] += MOD - F[r - l - 1];
      imosB[l] %= MOD;
      imosB[r] %= MOD;
      imosB[r + 1] %= MOD;
    }
    if (imosA[l] != imosB[l]){
      cnt++;
    }
    if (imosA[r] != imosB[r]){
      cnt++;
    }
    if (imosA[r + 1] != imosB[r + 1]){
      cnt++;
    }
    if (cnt == 0){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}