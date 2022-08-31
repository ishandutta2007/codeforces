#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 2; i * i <= n; i++){
    while (n % i == 0){
      a.push_back(i);
      n /= i;
    }
  }
  if (n > 1){
    a.push_back(n);
  }
  int sz = a.size();
  if (sz < k){
    cout << -1 << endl;
  } else {
    vector<int> ans(k, 1);
    for (int i = 0; i < sz; i++){
      ans[min(i, k - 1)] *= a[i];
    }
    for (int i = 0; i < k; i++){
      cout << ans[i];
      if (i < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}