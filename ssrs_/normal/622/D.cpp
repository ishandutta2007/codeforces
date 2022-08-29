#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> ans(n * 2, n);
  for (int i = 1; i < n; i++){
    if (i % 2 == 1){
      ans[i / 2] = i;
      ans[n - 1 - i / 2] = i;
    } else {
      ans[n - 1 + i / 2] = i;
      ans[n * 2 - 1 - i / 2] = i;
    }
  }
  for (int i = 0; i < n * 2; i++){
    cout << ans[i];
    if (i < n * 2 - 1){
      cout << ' ';
    }
  }
  cout << endl;
}