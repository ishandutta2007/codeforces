#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> ans(n);
    ans[0] = 1;
    ans[1] = 2;
    int x = 3;
    for (int j = 2; j < n - 1; j++){
      ans[j] = (j - 1) * 4;
      x ^= ans[j];
    }
    ans[n - 1] = x;
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}