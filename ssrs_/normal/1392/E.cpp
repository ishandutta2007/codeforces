#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (j % 2 == 0){
        a[i][j] = (long long) 1 << (i + j);
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << a[i][j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long k;
    cin >> k;
    vector<pair<int, int>> ans;
    int y = 0;
    int x = 0;
    k--;
    ans.push_back(make_pair(y, x));
    while (y != n - 1 || x != n - 1){
      bool right = true;
      if (x == n - 1){
        right = false;
      } else {
        long long X = (long long) 1 << (y + x + 1);
        if (a[y][x + 1] == 0){
          if ((k & X) != 0){
            right = false;
          }
        } else {
          if ((k & X) == 0){
            right = false;
          }
        }
      }
      if (right){
        x++;
      } else {
        y++;
      }
      ans.push_back(make_pair(y, x));
    }
    for (auto P : ans){
      cout << P.first + 1 << ' ' << P.second + 1 << endl;
    }
  }
}