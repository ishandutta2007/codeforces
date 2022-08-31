#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    x %= MOD;
    if (x < 0){
      x += MOD;
    }
    i++;
    while (i <= N){
      BIT[i] += x;
      BIT[i] %= MOD;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      ans %= MOD;
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return (sum(R) - sum(L) + MOD) % MOD;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++){
    cin >> l[i] >> r[i];
    l[i]--;
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + b[i];
  }
  vector<long long> T(n + 1);
  for (int i = 0; i <= n; i++){
    T[i] = (S[i] % MOD + MOD) % MOD;
  }
  vector<pair<long long, int>> P(n + 1);
  for (int i = 0; i <= n; i++){
    P[i] = make_pair(S[i], i);
  }
  sort(P.begin(), P.end());
  vector<vector<int>> query(n + 1);
  for (int i = 0; i < q; i++){
    query[l[i]].push_back(i);
  }
  vector<long long> ans(q, 0);
  binary_indexed_tree<long long> BIT1(n + 1), BIT2(n + 1), BIT3(n + 1), BIT4(n + 1);
  for (int i = 0; i < n; i++){
    BIT1.add(i, a[i]);
    BIT2.add(i, T[i] * a[i]);
  }
  for (int i = 1; i <= n; i++){
    BIT3.add(i, a[i - 1]);
    BIT4.add(i, T[i] * a[i - 1]);
  }
  for (int i = 0; i <= n; i++){
    int p = P[i].second;
    if (p < n){
      BIT1.add(p, -2 * a[p]);
      BIT2.add(p, -2 * T[p] * a[p]);
    }
    if (p > 0){
      BIT3.add(p, -2 * a[p - 1]);
      BIT4.add(p, -2 * T[p] * a[p - 1]);
    }
    for (int j : query[p]){
      ans[j] -= BIT1.sum(l[j], r[j]) * T[l[j]];
      ans[j] += BIT2.sum(l[j], r[j]);
      ans[j] += BIT3.sum(l[j] + 1, r[j] + 1) * T[l[j]];
      ans[j] -= BIT4.sum(l[j] + 1, r[j] + 1);
    }
  }
  for (int i = 0; i < q; i++){
    ans[i] %= MOD;
    if (ans[i] < 0){
      ans[i] += MOD;
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}