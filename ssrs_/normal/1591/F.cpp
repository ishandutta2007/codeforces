#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
struct affine{
  long long a;
  long long b;
  affine(){
    a = 1;
    b = 0;
  }
  affine(long long A, long long B){
    a = A;
    b = B;
  }
};
affine composite(affine f, affine g){
  return affine(f.a * g.a % MOD, (f.b * g.a + g.b) % MOD);
}
struct lazy_segment_tree{
  int N;
  vector<long long> sum;
  vector<long long> wsum;
  vector<affine> lazy;
  lazy_segment_tree(vector<long long> &A, vector<long long> &B){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    sum = vector<long long>(N * 2 - 1, 0);
    wsum = vector<long long>(N * 2 - 1, 0);
    lazy = vector<affine>(N * 2 - 1, affine());
    for (int i = 0; i < n; i++){
      sum[N - 1 + i] = A[i] * B[i] % MOD;
      wsum[N - 1 + i] = B[i];
    }
    for (int i = N - 2; i >= 0; i--){
      sum[i] = (sum[i * 2 + 1] + sum[i * 2 + 2]) % MOD;
      wsum[i] = (wsum[i * 2 + 1] + wsum[i * 2 + 2]) % MOD;
    }
  }
  void eval(int i){
    if (i < N - 1){
      lazy[i * 2 + 1] = composite(lazy[i * 2 + 1], lazy[i]);
      lazy[i * 2 + 2] = composite(lazy[i * 2 + 2], lazy[i]);
    }
    sum[i] = (sum[i] * lazy[i].a + wsum[i] * lazy[i].b) % MOD;
    lazy[i] = affine();
  }
  void range_affine(int L, int R, affine f, int i, int l, int r){
    eval(i);
    if (R <= l || r <= L){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = f;
      eval(i);
    } else {
      int m = (l + r) / 2;
      range_affine(L, R, f, i * 2 + 1, l, m);
      range_affine(L, R, f, i * 2 + 2, m, r);
      sum[i] = (sum[i * 2 + 1] + sum[i * 2 + 2]) % MOD;
    }
  }
  void range_affine(int L, int R, affine f){
    range_affine(L, R, f, 0, 0, N);
  }
  long long range_sum(int L, int R, int i, int l, int r){
    eval(i);
    if (R <= l || r <= L){
      return 0;
    } else if (L <= l && r <= R){
      return sum[i];
    } else {
      int m = (l + r) / 2;
      return (range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r)) % MOD;
    }
  }
  long long range_sum(int L, int R){
    return range_sum(L, R, 0, 0, N);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<pair<int, int>> P(N);
  for (int i = 0; i < N; i++){
    P[i] = make_pair(A[i], i);
  }
  sort(P.begin(), P.end());
  vector<int> pos(N);
  for (int i = 0; i < N; i++){
    pos[P[i].second] = i;
  }
  vector<long long> B(N);
  B[0] = P[0].first;
  for (int i = 0; i < N - 1; i++){
    B[i + 1] = P[i + 1].first - P[i].first;
  }
  vector<long long> s(N, 0);
  for (int i = 0; i <= pos[0]; i++){
    s[i] = 1;
  }
  lazy_segment_tree ST(s, B);
  for (int i = 0; i < N - 1; i++){
    long long sum = ST.range_sum(0, N);
    ST.range_affine(0, pos[i + 1] + 1, affine(MOD - 1, sum));
    ST.range_affine(pos[i + 1] + 1, N, affine(0, 0));
  }
  cout << ST.range_sum(0, N) << endl;
}