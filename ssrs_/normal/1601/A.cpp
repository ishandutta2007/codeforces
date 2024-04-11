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
    vector<int> cnt(30, 0);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 30; k++){
        if ((a[j] >> k & 1) == 1){
          cnt[k]++;
        }
      }
    }
    int g = 0;
    for (int j = 0; j < 30; j++){
      g = __gcd(g, cnt[j]);
    }
    vector<int> ans;
    for (int j = 1; j <= n; j++){
      if (g % j == 0){
        ans.push_back(j);
      }
    }
    int x = ans.size();
    for (int j = 0; j < x; j++){
      cout << ans[j];
      if (j < x - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}