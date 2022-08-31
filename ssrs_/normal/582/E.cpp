#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void fwt1(array<long long, 65536> &f){
  for (int i = 1; i < 65536; i <<= 1){
    for (int j = 0; j < 65536; j++){
      if ((j & i) == 0){
        f[j] += f[j | i];
        if (f[j] >= MOD){
          f[j] -= MOD;
        }
      }
    }
  }
}
void ifwt1(array<long long, 65536> &f){
  for (int i = 1; i < 65536; i <<= 1){
    for (int j = 0; j < 65536; j++){
      if ((j & i) == 0){
        f[j] -= f[j | i];
        if (f[j] < 0){
          f[j] += MOD;
        }
      }
    }
  }
}
array<long long, 65536> and_convolution(array<long long, 65536> A, array<long long, 65536> B){
  fwt1(A);
  fwt1(B);
  array<long long, 65536> C;
  for (int i = 0; i < 65536; i++){
    C[i] = A[i] * B[i] % MOD;
  }
  ifwt1(C);
  return C;
}
void fwt2(array<long long, 65536> &f){
  for (int i = 1; i < 65536; i <<= 1){
    for (int j = 0; j < 65536; j++){
      if ((j & i) == 0){
        f[j | i] += f[j];
        if (f[j | i] >= MOD){
          f[j | i] -= MOD;
        }
      }
    }
  }
}
void ifwt2(array<long long, 65536> &f){
  for (int i = 1; i < 65536; i <<= 1){
    for (int j = 0; j < 65536; j++){
      if ((j & i) == 0){
        f[j | i] -= f[j];
        if (f[j | i] < 0){
          f[j | i] += MOD;
        }
      }
    }
  }
}
array<long long, 65536> or_convolution(array<long long, 65536> A, array<long long, 65536> B){
  fwt2(A);
  fwt2(B);
  array<long long, 65536> C;
  for (int i = 0; i < 65536; i++){
    C[i] = A[i] * B[i] % MOD;
  }
  ifwt2(C);
  return C;
}
array<long long, 65536> add(array<long long, 65536> A, array<long long, 65536> B){
  array<long long, 65536> C;
  for (int i = 0; i < 65536; i++){
    C[i] = A[i] + B[i];
    if (C[i] >= MOD){
      C[i] -= MOD;
    }
  }
  return C;
}
array<array<long long, 65536>, 9> C;
array<long long, 65536> variable(string &s, int &x){
  char c = s[x];
  x++;
  if (c == 'A'){
    return C[0];
  }
  if (c == 'B'){
    return C[1];
  }
  if (c == 'C'){
    return C[2];
  }
  if (c == 'D'){
    return C[3];
  }
  if (c == 'a'){
    return C[4];
  }
  if (c == 'b'){
    return C[5];
  }
  if (c == 'c'){
    return C[6];
  }
  if (c == 'd'){
    return C[7];
  }
  if (c == '?'){
    return C[8];
  }
}
array<long long, 65536> expression(string &s, int &x){
  if (s[x] != '('){
    return variable(s, x);
  }
  x++;
  array<long long, 65536> X = expression(s, x);
  x++;
  char op = s[x];
  x++;
  x++;
  array<long long, 65536> Y = expression(s, x);
  x++;
  if (op == '&'){
    return and_convolution(X, Y);
  } else if (op == '|'){
    return or_convolution(X, Y);
  } else {
    return add(and_convolution(X, Y), or_convolution(X, Y));
  }
}
void precalc(){
  for (int i = 0; i < 65536; i++){
    for (int j = 0; j < 9; j++){
      C[j][i] = 0;
    }
  }
  C[0][0b1010101010101010] = 1;
  C[1][0b1100110011001100] = 1;
  C[2][0b1111000011110000] = 1;
  C[3][0b1111111100000000] = 1;
  C[4][0b0101010101010101] = 1;
  C[5][0b0011001100110011] = 1;
  C[6][0b0000111100001111] = 1;
  C[7][0b0000000011111111] = 1;
  for (int i = 0; i < 8; i++){
    C[8] = add(C[8], C[i]);
  }
}
int main(){
  precalc();
  string s;
  cin >> s;
  int x = 0;
  array<long long, 65536> P = expression(s, x);
  int n;
  cin >> n;
  vector<bool> ok(65536, true);
  for (int i = 0; i < n; i++){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int x = a + b * 2 + c * 4 + d * 8;
    for (int j = 0; j < 65536; j++){
      if (((j >> x) & 1) != e){
        ok[j] = false;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 65536; i++){
    if (ok[i]){
      ans += P[i];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}