#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> ans;
    for (int j = 0; j * j <= n; j++){
      ans.push_back(j);
    }
    for (int j = 1; j * j < n; j++){
      ans.push_back(n / j);
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