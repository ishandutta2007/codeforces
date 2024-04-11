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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> a2 = a;
    sort(a2.begin(), a2.end());
    a2.erase(unique(a2.begin(), a2.end()), a2.end());
    int cnt = a2.size();
    for (int j = 0; j < n; j++){
      a[j] = lower_bound(a2.begin(), a2.end(), a[j]) - a2.begin();
    }
    binary_indexed_tree<int> BIT(cnt);
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += min(BIT.sum(a[j]), BIT.sum(a[j] + 1, cnt));
      BIT.add(a[j], 1);
    }
    cout << ans << endl;
  }
}