#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int j = (k + 1) / 2; j < k; j++){
      ans.push_back(j);
    }
    for (int j = k + 1; j <= n; j++){
      ans.push_back(j);
    }
    int m = ans.size();
    cout << m << endl;
    for (int j = 0; j < m; j++){
      cout << ans[j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}