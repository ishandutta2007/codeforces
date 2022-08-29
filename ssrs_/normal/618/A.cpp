#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 17; i >= 0; i--){
    if ((n >> i & 1) == 1){
      ans.push_back(i + 1);
    }
  }
  int k = ans.size();
  for (int i = 0; i < k; i++){
    cout << ans[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}