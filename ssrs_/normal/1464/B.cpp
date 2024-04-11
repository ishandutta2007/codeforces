#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  string s;
  cin >> s;
  long long x, y;
  cin >> x >> y;
  int N = s.size();
  long long cost1 = 0;
  vector<int> cnt(2, 0);
  vector<int> zero, one;
  vector<int> q;
  for (int i = 0; i < N; i++){
    if (s[i] == '0'){
      cost1 += cnt[1] * y;
      cnt[0]++;
      zero.push_back(i);
    }
    if (s[i] == '1'){
      cost1 += cnt[0] * x;
      cnt[1]++;
      one.push_back(i);
    }
    if (s[i] == '?'){
      q.push_back(i);
    }
  }
  int M = q.size();
  vector<long long> A(M), B(M);
  for (int i = 0; i < M; i++){
    int c1 = lower_bound(one.begin(), one.end(), q[i]) - one.begin();
    A[i] = c1 * y + (cnt[1] - c1) * x;
    int c0 = lower_bound(zero.begin(), zero.end(), q[i]) - zero.begin();
    B[i] = c0 * x + (cnt[0] - c0) * y;
  }
  if (x >= y){
    vector<long long> L(M + 1);
    L[0] = 0;
    for (int i = 0; i < M; i++){
      L[i + 1] = L[i] + B[i];
    }
    vector<long long> R(M + 1);
    R[M] = 0;
    for (int i = M - 1; i >= 0; i--){
      R[i] = R[i + 1] + A[i];
    }
    long long ans = INF;
    for (long long i = 0; i <= M; i++){
      ans = min(ans, cost1 + L[i] + R[i] + y * (i * (M - i)));
    }
    cout << ans << endl;
  } else {
    vector<long long> L(M + 1);
    L[0] = 0;
    for (int i = 0; i < M; i++){
      L[i + 1] = L[i] + A[i];
    }
    vector<long long> R(M + 1);
    R[M] = 0;
    for (int i = M - 1; i >= 0; i--){
      R[i] = R[i + 1] + B[i];
    }
    long long ans = INF;
    for (long long i = 0; i <= M; i++){
      ans = min(ans, cost1 + L[i] + R[i] + x * (i * (M - i)));
    }
    cout << ans << endl;
  }
}