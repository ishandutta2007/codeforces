#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    vector<int> ans(n);
    ans[0] = a[0];
    for (int j = 1; j < n - 1; j++){
      if (ans[j - 1] == a[j]){
        ans[j] = b[j];
      } else {
        ans[j] = a[j];
      }
    }
    if (ans[0] != a[n - 1] && ans[n - 2] != a[n - 1]){
      ans[n - 1] = a[n - 1];
    }
    if (ans[0] != b[n - 1] && ans[n - 2] != b[n - 1]){
      ans[n - 1] = b[n - 1];
    }
    if (ans[0] != c[n - 1] && ans[n - 2] != c[n - 1]){
      ans[n - 1] = c[n - 1];
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}