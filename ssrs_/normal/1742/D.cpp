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
    vector<vector<int>> C(1001);
    for (int j = 0; j < n; j++){
      C[a[j]].push_back(j);
    }
    int ans = -1;
    for (int j = 1; j <= 1000; j++){
      if (!C[j].empty()){
        for (int k = j + 1; k <= 1000; k++){
          if (!C[k].empty() && gcd(j, k) == 1){
            ans = max(ans, C[j].back() + C[k].back() + 2);
          }
        }
      }
    }
    if (!C[1].empty()){
      ans = max(ans, C[1].back() * 2 + 2);
    }
    cout << ans << endl;
  }
}