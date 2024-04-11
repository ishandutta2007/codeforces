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
    vector<int> cnt(n, 0);
    for (int j = 0; j < n - 1; j++){
      cnt[a[j]]++;
    }
    long long ans = 0;
    vector<vector<int>> cnt2(n, vector<int>(n, 0));
    for (int j = n - 1; j >= 0; j--){
      for (int k = 0; k < n; k++){
        ans += (long long) cnt[k] * cnt2[k][a[j]];
      }
      for (int k = j + 1; k < n; k++){
        cnt2[a[j]][a[k]]++;
      }
      if (j > 0){
        cnt[a[j - 1]]--;
      }
    }
    cout << ans << endl;
  }
}