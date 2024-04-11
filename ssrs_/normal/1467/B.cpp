#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
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
    int cnt = 0;
    for (int j = 1; j < n - 1; j++){
      if (a[j - 1] < a[j] && a[j] > a[j + 1]){
        cnt++;
      }
      if (a[j - 1] > a[j] && a[j] < a[j + 1]){
        cnt++;
      }
    }
    int ans = cnt;
    vector<int> b = a;
    if (n >= 3){
      for (int j = 0; j < n; j++){
        vector<int> c;
        for (int k = j - 2; k <= j + 2; k++){
          if (0 <= k && k < n){
            c.push_back(a[k]);
          }
        }
        c.push_back(0);
        c.push_back(INF);
        int sz = c.size();
        for (int k = 0; k < sz; k++){
          b[j] = c[k];
          int add = 0;
          for (int l = j - 1; l <= j + 1; l++){
            if (1 <= l && l < n - 1){
              if (a[l - 1] < a[l] && a[l] > a[l + 1]){
                add--;
              }
              if (a[l - 1] > a[l] && a[l] < a[l + 1]){
                add--;
              }
              if (b[l - 1] < b[l] && b[l] > b[l + 1]){
                add++;
              }
              if (b[l - 1] > b[l] && b[l] < b[l + 1]){
                add++;
              }
            }
          }
          ans = min(ans, cnt + add);
        }
        b[j] = a[j];
      }
    }
    cout << ans << "\n";
  }
}