#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n / k);
  for (int i = 0; i < n / k; i++){
    for (int j = i * k; j < i * k + k; j++){
      cout << "? " << j + 1 << endl;
      char c;
      cin >> c;
      if (c == 'N'){
        a[i].push_back(j);
      }
    }
    cout << "R" << endl;
  }
  int ans = 0;
  for (int i = 0; i < n / k; i++){
    int cnt = a[i].size();
    vector<bool> ok(cnt, true);
    for (int j = 0; j < i; j++){
      int cnt2 = a[j].size();
      for (int l = 0; l < cnt2; l++){
        cout << "? " << a[j][l] + 1 << endl;
        char c;
        cin >> c;
      }
      for (int l = 0; l < cnt; l++){
        cout << "? " << a[i][l] + 1 << endl;
        char c;
        cin >> c;
        if (c == 'Y'){
          ok[l] = false;
        }
      }
      cout << "R" << endl;
      for (int l = cnt2 - 1; l >= 0; l--){
        cout << "? " << a[j][l] + 1 << endl;
        char c;
        cin >> c;
      }
      for (int l = cnt - 1; l >= 0; l--){
        cout << "? " << a[i][l] + 1 << endl;
        char c;
        cin >> c;
        if (c == 'Y'){
          ok[l] = false;
        }
      }
      cout << "R" << endl;
    }
    for (int j = 0; j < cnt; j++){
      if (ok[j]){
        ans++;
      }
    }
  }
  cout << "! " << ans << endl;
}