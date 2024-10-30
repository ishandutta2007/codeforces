#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> mn(n);
    mn[0] = p[0];
    for (int j = 1; j < n; j++){
      mn[j] = min(mn[j - 1], p[j]);
    }
    vector<int> ans;
    for (int j = n - 1; j >= 0; j--){
      if (mn[j] == p[j]){
        ans.push_back(p[j]);
      }
    }
    for (int j = 0; j < n; j++){
      if (mn[j] != p[j]){
        ans.push_back(p[j]);
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}