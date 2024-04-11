#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct invertible_binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  function<T(T)> inv;
  T E;
  invertible_binary_indexed_tree(){
  }
  invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)> inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){
  }
  invertible_binary_indexed_tree(vector<T> &A, function<T(T, T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1), f(f), inv(inv), E(E){
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      if (i + (i & -i) <= N){
        BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);
      }
    }
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] = f(BIT[i], x);
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = E;
    while (i > 0){
      ans = f(ans, BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
  T sum(int l, int r){
    return f(sum(r), inv(sum(l)));
  }
};
int main(){
  int t;
  cin >> t;
  vector<int> l(t), r(t);
  for (int i = 0; i < t; i++){
    cin >> l[i] >> r[i];
  }
  vector<vector<int>> query(200001);
  for (int i = 0; i < t; i++){
    query[l[i]].push_back(i);
  }
  vector<int> cnt(200001, 0);
  invertible_binary_indexed_tree<long long> BIT(200001, plus<long long>(), negate<long long>(), 0);
  vector<long long> ans(t);
  for (int i = 200000; i >= 1; i--){
    for (int j = i * 2; j <= 200000; j += i){
      BIT.add(j, cnt[j]);
      cnt[j]++;
    }
    for (int j : query[i]){
      ans[j] = BIT.sum(l[j], r[j] + 1);
    }
  }
  for (int i = 0; i < t; i++){
    ans[i] += max(r[i] / 6 - (l[i] * 2 - 1) / 6, 0);
    ans[i] += max(r[i] / 15 - (l[i] * 5 / 2 - 1) / 15, 0);
  }
  for (int i = 0; i < t; i++){
    long long all = (long long) (r[i] - l[i] + 1) * (r[i] - l[i]) * (r[i] - l[i] - 1) / 6;
    cout << all - ans[i] << "\n";
  }
}