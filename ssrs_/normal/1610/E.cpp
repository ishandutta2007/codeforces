#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = 1;
    for (int j = 0; j < n - 1; j++){
      long long d = a[j + 1] - a[j];
      if (j > 0){
        if (a[j - 1] == a[j]){
          continue;
        }
      }
      int cnt = 2;
      int p = j + 1;
      while (true){
        int p2 = lower_bound(a.begin() + p + 1, a.end(), a[j] + d * 2) - a.begin();
        if (p2 == n){
          break;
        }
        p = p2;
        d = a[p2] - a[j];
        cnt++;
      }
      ans = max(ans, cnt);
    }
    cout << n - ans << endl;
  }
}