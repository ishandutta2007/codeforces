#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    for (int j = 0; j < 2; j++){
      int sa = (a + b + j) / 2, sb = (a + b + 1 - j) / 2;
      for (int k = 0; k <= a + b; k++){
        if (a - k >= 0 && sb - k >= 0 && b - (sb - k) >= 0){
          ans.push_back(k + b - (sb - k));
        }
      }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
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