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
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    if (*max_element(cnt.begin(), cnt.end()) > (n + 1) / 2){
      cout << -1 << endl;
    } else {
      vector<int> cnt2(n, 0);
      cnt2[a[0]]++;
      cnt2[a[n - 1]]++;
      int sum = 2;
      for (int j = 0; j < n - 1; j++){
        if (a[j] == a[j + 1]){
          cnt2[a[j]] += 2;
          sum += 2;
        }
      }
      int mx = *max_element(cnt2.begin(), cnt2.end());
      if (mx <= sum / 2 + 1){
        cout << sum / 2 - 1 << endl;
      } else {
        cout << (sum / 2 - 1) + ((mx * 2 - 2) - sum) / 2 << endl;
      }
    }
  }
}