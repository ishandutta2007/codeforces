#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(c + 1, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    vector<int> sum(c + 2, 0);
    for (int j = 0; j <= c; j++){
      sum[j + 1] = sum[j] + cnt[j];
    }
    bool ok = true;
    if (cnt[1] == 0){
      ok = false;
    }
    for (int j = 1; j <= c; j++){
      if (cnt[j] >= 1){
        for (int k = 1; j * k <= c; k++){
          if (cnt[k] == 0){
            int a = j * k, b = min(j * (k + 1) - 1, c);
            if (sum[b + 1] - sum[a] > 0){
              ok = false;
            }
          }
        }
      }
    }
    if (ok){
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}