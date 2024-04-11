#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (a[j] == b[k]){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}