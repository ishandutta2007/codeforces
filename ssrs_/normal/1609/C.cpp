#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int main(){
  vector<bool> prime(MAX, true);
  prime[1] = false;
  for (int i = 2; i < MAX; i++){
    if (prime[i]){
      for (int j = i * 2; j < MAX; j += i){
        prime[j] = false;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long ans = 0;
    for (int j = 0; j < e; j++){
      vector<int> b;
      for (int k = j; k < n; k += e){
        b.push_back(a[k]);
      }
      int m = b.size();
      set<int> pr, co;
      for (int k = 0; k < m; k++){
        if (b[k] > 1){
          if (prime[b[k]]){
            pr.insert(k);
          } else {
            co.insert(k);
          }
        }
      }
      pr.insert(m);
      pr.insert(m);
      co.insert(m);
      for (int k = 0; k < m; k++){
        auto itr1 = pr.lower_bound(k);
        auto itr2 = next(itr1);
        auto itr3 = co.lower_bound(k);
        int L = max(*itr1, k + 1);
        int R = min(*itr2, *itr3);
        ans += max(R - L, 0);
      }
    }
    cout << ans << "\n";
  }
}