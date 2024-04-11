#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int sum = 1;
    int f = 0;
    vector<int> pos;
    for (int j = 1; j < n; j++){
      vector<int> L;
      for (int k = 0; k < j; k++){
        if (sum == 0){
          if (k == pos[0]){
            continue;
          }
        }
        L.push_back(k);
      }
      int l = L.size();
      int r = 1;
      cout << "? " << l << ' ' << r << endl;
      for (int k = 0; k < l; k++){
        cout << L[k] + 1;
        if (k < l - 1){
          cout << ' ';
        }
      }
      cout << endl;
      cout << j + 1 << endl;
      int F;
      cin >> F;
      if (F != 0){
        pos.push_back(j);
        bool N;
        if (sum != 0){
          N = (F > 0) == (sum > 0);
        } else {
          N = (f != F);
        }
        if (!N){
          sum--;
          if (pos.size() == 1){
            f = -1;
          }
        } else {
          sum++;
          if (pos.size() == 1){
            f = 1;
          }
        }
      }
    }
    int tv = pos[0], fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      cout << "? " << mid << ' ' << 1 << endl;
      for (int k = 0; k < mid; k++){
        cout << k + 1;
        if (k < mid - 1){
          cout << ' ';
        }
      }
      cout << endl;
      cout << pos[0] + 1 << endl;
      int F;
      cin >> F;
      if (F != 0){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    vector<bool> zero(n, true);
    zero[fv] = false;
    for (int j : pos){
      zero[j] = false;
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
      if (zero[j]){
        ans.push_back(j);
      }
    }
    int k = ans.size();
    cout << "! " << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << ans[j] + 1;
    }
    cout << endl;
  }
}