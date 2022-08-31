#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<bool> used(n, false);
    vector<int> ans(n);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        vector<int> X;
        while (true){
          cout << "? " << j + 1 << endl;
          int res;
          cin >> res;
          res--;
          X.push_back(res);
          if (X.size() >= 2 && X[0] == X.back()){
            break;
          }
        }
        int cnt = X.size();
        for (int k = 0; k < cnt - 1; k++){
          ans[X[k]] = X[k + 1];
          used[X[k]] = true;
        }
      }
    }
    cout << "!";
    for (int j = 0; j < n; j++){
      cout << ' ' << ans[j] + 1;
    }
    cout << endl;
  }
}