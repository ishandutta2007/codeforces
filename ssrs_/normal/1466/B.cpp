#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
      x[j]--;
    }
    vector<int> cnt(n * 2, 0);
    for (int j = 0; j < n; j++){
      cnt[x[j]]++;
    }
    vector<bool> used(n * 2 + 1, false);
    for (int j = 0; j < n * 2; j++){
      if (cnt[j] >= 2){
        used[j] = true;
        used[j + 1] = true;
      }
    }
    for (int j = 0; j < n * 2; j++){
      if (cnt[j] == 1){
        if (!used[j]){
          used[j] = true;
        } else {
          used[j + 1] = true;
        }
      }
    }
    int ans = 0;
    for (int j = 0; j <= n * 2; j++){
      if (used[j]){
        ans++;
      }
    }
    cout << ans << endl;
  }
}