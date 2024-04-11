#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    bool ok = true;
    if (n < 62){
      if (k > (((long long) 1) << (n - 1))){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << "\n";
    } else {
      k--;
      vector<int> p;
      p.push_back(0);
      for (int j = 1; j < n; j++){
        if (n - 1 - j > 60){
          p.push_back(j);
        } else {
          if ((k >> (n - 1 - j) & 1) == 0){
            p.push_back(j);
          }
        }
      }
      p.push_back(n);
      int cnt = p.size();
      vector<int> ans(n);
      for (int j = 0; j < n; j++){
        ans[j] = j;
      }
      for (int j = 0; j < cnt - 1; j++){
        int l = p[j], r = p[j + 1];
        reverse(ans.begin() + l, ans.begin() + r);
      }
      for (int j = 0; j < n; j++){
        cout << ans[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  }
}