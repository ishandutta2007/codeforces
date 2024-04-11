#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct invertible_binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  function<T(T)> inv;
  T E;
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
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int j = 0; j < m; j++){
      cin >> a[j];
      a[j]--;
    }
    sort(a.begin(), a.end());
    vector<long long> b(m);
    for (int j = 0; j < m - 1; j++){
      b[j] = a[j + 1] - a[j] - 1;
    }
    b[m - 1] = a[0] + n - a[m - 1] - 1;
    sort(b.begin(), b.end(), greater<int>());
    int ans = 0;
    for (int j = 0; j < m; j++){
      if (b[j] > j * 4 + 1){
        ans += b[j] - (j * 4 + 1);
      } else if (b[j] == j * 4 + 1){
        ans++;
      }
    }
    cout << n - ans <<endl;
  }
}