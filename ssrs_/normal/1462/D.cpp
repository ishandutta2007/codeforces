#include <bits/stdc++.h>
using namespace std;
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
    vector<int> S(n + 1, 0);
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    set<int> st;
    for (int j = 0; j <= n; j++){
      st.insert(S[j]);
    }
    int sum = S[n];
    vector<int> f;
    for (int j = 1; j * j <= sum; j++){
      if (sum % j == 0){
        f.push_back(j);
        if (j * j < sum){
          f.push_back(sum / j);
        }
      }
    }
    int ans = n - 1;
    for (int j : f){
      bool ok = true;
      for (int k = 0; k <= sum; k += j){
        if (!st.count(k)){
          ok = false;
          break;
        }
      }
      if (ok){
        ans = min(ans, n - sum / j);
      }
    }
    cout << ans << endl;
  }
}