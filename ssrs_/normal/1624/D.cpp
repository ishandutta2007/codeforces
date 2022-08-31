#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < n; j++){
      cnt[s[j] - 'a']++;
    }
    int tv = 0, fv = n / k + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      bool ok = true;
      if (mid % 2 == 0){
        int sum = 0;
        for (int j = 0; j < 26; j++){
          sum += cnt[j] / 2;
        }
        if (sum < mid / 2 * k){
          ok = false;
        }
      }
      if (mid % 2 == 1){
        vector<int> cnt2 = cnt;
        int odd = 0;
        for (int j = 0; j < 26; j++){
          if (cnt2[j] % 2 == 1 && odd < k){
            cnt2[j]--;
            odd++;
          }
        }
        for (int j = 0; j < 26; j++){
          while (cnt2[j] >= 2 && odd < k){
            cnt2[j] -= 2;
            odd += 2;
          }
        }
        if (odd < k){
          ok = false;
        } else {
          int sum = 0;
          for (int j = 0; j < 26; j++){
            sum += cnt2[j] / 2;
          }
          if (sum < mid / 2 * k){
            ok = false;
          }
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}