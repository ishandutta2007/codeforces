#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    int mx = -1;
    int ans = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, p[j]);
      if (mx == j){
        ans++;
      }
    }
    cout << ans << "\n";
  }
}