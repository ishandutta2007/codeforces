#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
long long c(long long x){
  long long t = 0;
  long long f = 1000000;
  while (f - t > 1){
    long long m = (t + f) / 2;
    if (m * m * m <= x){
      t = m;
    } else {
      f = m;
    }
  }
  return t;
}
int main(){
  long long m;
  cin >> m;
  vector<long long> A;
  long long sum = 0;
  A.push_back(1);
  sum += 1;
  while (A.size() < 19){
    long long tv = 500000;
    long long fv = 0;
    while (tv - fv > 1){
      long long mid = (tv + fv) / 2;
      if (c(sum + mid * mid * mid) == mid){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    A.push_back(tv);
    sum += tv * tv * tv;
  }
  int sz = 0;
  for (int i = 1; i <= 19; i++){
    long long tmp = 0;
    for (int j = 0; j < i; j++){
      tmp += A[j] * A[j] * A[j];
    }
    if (tmp <= m){
      sz = i;
    } else {
      break;
    }
  }
  vector<long long> S(19);
  S[0] = A[0] * A[0] * A[0];
  for (int i = 1; i < 19; i++){
    S[i] = S[i - 1] + A[i] * A[i] * A[i];
  }
  long long sum2 = 0;
  long long M = 1000000000000000000;
  for (int i = 0; i < sz; i++){
    long long t = c(m - sum2);
    if (i < sz - 1){
      while (m - sum2 - t * t * t < S[sz - i - 2] || t * t * t >= M - S[sz - i - 2]){
        t--;
      }
    }
    if (i == sz - 1){
      t = 1;
    }
    sum2 += t * t * t;
    M = min(M, (t + 1) * (t + 1) * (t + 1)) - t * t * t;
  }
  cout << sz << ' ' << sum2 << endl;
}