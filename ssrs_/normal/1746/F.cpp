#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(vector<T> &A){
    N = A.size();
    BIT = vector<T>(N + 1, 0);
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      if (i + (i & -i) <= N){
        BIT[i + (i & -i)] += BIT[i];
      }
    }
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int l, int r){
    return sum(r) - sum(l);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dist(0, 999999999);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> t(q);
  vector<int> A(q), B(q), C(q);
  for (int i = 0; i < q; i++){
    cin >> t[i];
    if (t[i] == 1){
      cin >> A[i] >> B[i];
      A[i]--;
    }
    if (t[i] == 2){
      cin >> A[i] >> B[i] >> C[i];
      A[i]--;
    }
  }
  vector<int> X;
  for (int i = 0; i < n; i++){
    X.push_back(a[i]);
  }
  for (int i = 0; i < q; i++){
    if (t[i] == 1){
      X.push_back(B[i]);
    }
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  int cnt = X.size();
  for (int i = 0; i < n; i++){
    a[i] = lower_bound(X.begin(), X.end(), a[i]) - X.begin();
  }
  for (int i = 0; i < q; i++){
    if (t[i] == 1){
      B[i] = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
    }
  }
  vector<bool> ok(q, true);
  for (int i = 0; i < 50; i++){
    vector<int> hash(cnt);
    for (int j = 0; j < cnt; j++){
      hash[j] = dist(mt);
    }
    vector<long long> s(n);
    for (int j = 0; j < n; j++){
      s[j] = hash[a[j]];
    }
    binary_indexed_tree<long long> BIT(s);
    for (int j = 0; j < q; j++){
      if (t[j] == 1){
        int p = A[j];
        int x = B[j];
        BIT.add(p, hash[x] - s[p]);
        s[p] = hash[x];
      }
      if (t[j] == 2){
        int l = A[j];
        int r = B[j];
        int k = C[j];
        if (BIT.sum(l, r) % k != 0){
          ok[j] = false;
        }
      }
    }
  }
  for (int i = 0; i < q; i++){
    if (t[i] == 2){
      if (ok[i]){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}