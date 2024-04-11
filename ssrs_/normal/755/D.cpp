#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
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
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  int n, k;
  cin >> n >> k;
  k = min(k, n - k);
  binary_indexed_tree<int> BIT(n);
  int p = 0;
  long long ans = 1;
  for (int i = 0; i < n; i++){
    int q = (p + k) % n;
    ans++;
    if (p < q){
      ans += BIT.sum(p, q);
    } else {
      ans += BIT.sum(p, n);
      ans += BIT.sum(0, q);
    }
    int pp = (p + n - k) % n;
    if (pp < p){
      ans += BIT.sum(pp + 1, p);
    } else {
      ans += BIT.sum(pp + 1, n);
      ans += BIT.sum(0, p);
    }
    BIT.add(p, 1);
    p = q;
    cout << ans;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}