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
    vector<bool> used(n, false);
    int P = 0;
    vector<int> ans;
    while (true){
      int mx = -1;
      int id = -1;
      for (int j = 0; j < n; j++){
        if (!used[j] && (P | a[j]) > mx){
          mx = P | a[j];
          id = j;
        }
      }
      if (id == -1 || mx == P){
        for (int j = 0; j < n; j++){
          if (!used[j]){
            ans.push_back(a[j]);
          }
        }
        break;
      } else {
        ans.push_back(a[id]);
        P |= a[id];
        used[id] = true;
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}