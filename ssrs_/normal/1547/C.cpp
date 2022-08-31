#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    int pa = 0, pb = 0;
    vector<int> ans;
    for (int j = 0; j < n + m; j++){
      char ch;
      if (pb == m){
        ch = 'a';
      } else if (pa == n){
        ch = 'b';
      } else if (a[pa] < b[pb]){
        ch = 'a';
      } else {
        ch = 'b';
      }
      if (ch == 'a'){
        if (a[pa] > k){
          break;
        } else {
          ans.push_back(a[pa]);
          if (a[pa] == 0){
            k++;
          }
          pa++;
        }
      }
      if (ch == 'b'){
        if (b[pb] > k){
          break;
        } else {
          ans.push_back(b[pb]);
          if (b[pb] == 0){
            k++;
          }
          pb++;
        }
      }
    }
    if (ans.size() < n + m){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n + m; j++){
        cout << ans[j];
        if (j < n + m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}