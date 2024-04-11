#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
template <typename T>
struct segment_tree{
  int N;
  vector<T> ST;
  function<T(T, T)> f;
  T E;
  segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  T query(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
    }
  }
  T query(int L, int R){
    return query(L, R, 0, 0, N);
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> x(n), p(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> p[j];
    }
    vector<long long> P;
    for (int j = 0; j < n; j++){
      P.push_back(x[j] - p[j]);
      P.push_back(x[j]);
      P.push_back(x[j] + p[j]);
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    int cnt = P.size();
    vector<long long> imos_a(cnt + 1, 0), imos_b(cnt + 1, 0);
    for (int j = 0; j < n; j++){
      int L = lower_bound(P.begin(), P.end(), x[j] - p[j]) - P.begin();
      int M = lower_bound(P.begin(), P.end(), x[j]) - P.begin();
      int R = lower_bound(P.begin(), P.end(), x[j] + p[j]) - P.begin();
      imos_a[L]++;
      imos_b[L] += p[j] - x[j];
      imos_a[M]--;
      imos_b[M] -= p[j] - x[j];
      imos_a[M]--;
      imos_b[M] += p[j] + x[j];
      imos_a[R]++;
      imos_b[R] -= p[j] + x[j];
    }
    for (int j = 0; j < cnt; j++){
      imos_a[j + 1] += imos_a[j];
      imos_b[j + 1] += imos_b[j];
    }
    vector<long long> sum(cnt);
    for (int j = 0; j < cnt; j++){
      sum[j] = imos_a[j] * P[j] + imos_b[j];
    }
    vector<long long> A(cnt), B(cnt);
    for (int j = 0; j < cnt; j++){
      A[j] = sum[j] - P[j];
      B[j] = sum[j] + P[j];
    }
    function<long long(long long, long long)> op = [](long long x, long long y){
      return max(x, y);
    };
    segment_tree<long long> ST1(sum, op, -INF);
    segment_tree<long long> ST2(A, op, -INF);
    segment_tree<long long> ST3(B, op, -INF);
    string s;
    for (int j = 0; j < n; j++){
      bool ok = true;
      int L = lower_bound(P.begin(), P.end(), x[j] - p[j]) - P.begin();
      int M = lower_bound(P.begin(), P.end(), x[j]) - P.begin();
      int R = lower_bound(P.begin(), P.end(), x[j] + p[j]) - P.begin();
      if (ST1.query(0, L) > m){
        ok = false;
      }
      if (ST2.query(L, M) > m + p[j] - x[j]){
        ok = false;
      }
      if (ST3.query(M, R) > m + p[j] + x[j]){
        ok = false;
      }
      if (ST1.query(R, cnt) > m){
        ok = false;
      }
      if (ok){
        s += '1';
      } else {
        s += '0';
      }
    }
    cout << s << endl;
  }
}