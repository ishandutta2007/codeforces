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
    vector<vector<int>> b(n);
    b[0] = {1};
    for (int j = 1; j < n; j++){
      b[j] = b[j - 1];
      if (a[j] == 1){
        b[j].push_back(1);
      } else {
        while (b[j].back() != a[j] - 1){
          b[j].pop_back();
        }
        b[j].back() = a[j];
      }
    }
    for (int j = 0; j < n; j++){
      int cnt = b[j].size();
      for (int k = 0; k < cnt; k++){
        cout << b[j][k];
        if (k < cnt - 1){
          cout << '.';
        }
      }
      cout << "\n";
    }
  }
}