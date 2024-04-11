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
      a[j]--;
    }
    int ans = 0;
    vector<bool> used(n, false);
    for (int j = n - 1; j >= 0; j--){
      if (used[a[j]]){
        ans = j + 1;
        break;
      }
      used[a[j]] = true;
    }
    cout << ans << endl;
  }
}