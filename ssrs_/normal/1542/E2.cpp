#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, mod;
  cin >> n >> mod;
  if (n <= 3){
    cout << 0 << endl;
  } else {
    vector<long long> perm(n + 1);
    perm[0] = 1;
    for (int i = 0; i < n; i++){
      perm[i + 1] = perm[i] * (n - i) % mod;
    }
    int mx = n * (n - 1) / 2;
    vector<vector<long long>> A(n);
    A[3] = {1, 2, 2, 1};
    for (int i = 4; i < n; i++){
      int cnt = A[i - 1].size();
      vector<long long> S(cnt + 1, 0);
      for (int j = 0; j < cnt; j++){
        S[j + 1] = S[j] + A[i - 1][j];
        S[j + 1] %= mod;
      }
      A[i] = vector<long long>(cnt + i - 1, 0);
      for (int j = 0; j < cnt + i - 1; j++){
        A[i][j] += S[min(j + 1, cnt)];
        A[i][j] -= S[max(j - i + 1, 0)];
        A[i][j] += mod;
        A[i][j] %= mod;
      }
    }
    long long ans = 0;
    for (int i = 3; i < n; i++){
      int cnt = A[i].size();
      vector<long long> B(cnt + i, 0);
      for (int j = 0; j < cnt; j++){
        B[i + j] = A[i][j];
      }
      int cnt2 = cnt + i;
      vector<long long> S1(cnt2 + 1), S2(cnt2 + 1), S3(cnt2 + 1);
      S1[0] = 0;
      S2[0] = 0;
      S3[0] = 0;
      for (int j = 0; j < cnt2; j++){
        S1[j + 1] = (S1[j] + B[j]) % mod;
        S2[j + 1] = (S2[j] + B[j] * j) % mod;
        S3[j + 1] = (S3[j] + B[j] * ((long long) j * (j + 1) / 2 % mod)) % mod;
      }
      for (int j = i + 1; j < cnt2; j++){
        long long x = i * (i + 1) / 2;
        long long tmp = 0;
        tmp += S1[j] * x % mod;
        tmp -= S3[j] - S3[j - i];
        tmp += (S2[j] - S2[j - i] + mod) % mod * (j - i - 1) % mod;
        long long y = (long long) (j - i - 1) * (j - i - 2) / 2 % mod;
        tmp -= (S1[j] - S1[j - i] + mod) % mod * y % mod;
        tmp += mod * 2;
        tmp %= mod;
        tmp *= A[i][j - i];
        tmp %= mod;
        ans += tmp * perm[n - 1 - i] % mod;
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
}