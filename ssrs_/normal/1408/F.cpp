#include <bits/stdc++.h>
using namespace std;
int f(int n){
  int ans = 1;
  while (ans < n){
    ans *= 2;
  }
  return ans / 2;
}
int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  int a = f(n);
  for (int i = 0; i < 16; i++){
    if ((1 << i) < a){
      for (int j = 0; j < a; j++){
        if (!(j >> i & 1)){
          ans.push_back(make_pair(j, j + (1 << i)));
        }
      }
    }
  }
  for (int i = 0; i < 16; i++){
    if ((1 << i) < a){
      for (int j = 0; j < a; j++){
        if (!(j >> i & 1)){
          ans.push_back(make_pair(n - 1 - j, n - 1 - j - (1 << i)));
        }
      }
    }
  }
  int q = ans.size();
  cout << q << endl;
  for (int i = 0; i < q; i++){
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
  }
}