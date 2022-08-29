#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<int> A;
    A.push_back(0);
    for (int j = 1; j < n; j++){
      if (s[j] != s[j - 1]){
        A.push_back(j);
      }
    }
    A.push_back(n);
    vector<int> ans(n);
    for (int j = 0; j < n; j++){
      ans[j] = j;
    }
    bool ok = true;
    int cnt = A.size() - 1;
    for (int j = 0; j < cnt; j++){
      if (A[j + 1] - A[j] == 1){
        ok = false;
      } else {
        rotate(ans.begin() + A[j], ans.begin() + A[j] + 1, ans.begin() + A[j + 1]);
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        cout << ans[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}