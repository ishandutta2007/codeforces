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
    vector<int> cnt(101, 0);
    for (int j = 0; j < n; j++){
      cnt[abs(a[j])]++;
    }
    int ans = 0;
    for (int j = 0; j <= 100; j++){
      int x = min(cnt[j], 2);
      if (j == 0){
        x = min(x, 1);
      }
      ans += x;
    }
    cout << ans << endl;
  }
}