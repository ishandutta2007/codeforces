#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<tuple<int, int, int>> ans(1001);
  for (int i = 0; i <= 1000; i++){
    ans[i] = make_tuple(-1, -1, -1);
  }
  for (int i = 0; i * 3 <= 1000; i++){
    for (int j = 0; i * 3 + j * 5 <= 1000; j++){
      for (int k = 0; i * 3 + j * 5 + k * 7 <= 1000; k++){
        ans[i * 3 + j * 5 + k * 7] = make_tuple(i, j, k);
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (get<0>(ans[n]) == -1){
      cout << -1 << endl;
    } else {
      cout << get<0>(ans[n]) << ' ' << get<1>(ans[n]) << ' ' << get<2>(ans[n]) << endl;
    }
  }
}