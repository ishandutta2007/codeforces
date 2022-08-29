#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % k != 0){
      cout << -1 << "\n";
    } else {
      vector<vector<int>> pos(26);
      for (int j = 0; j < n; j++){
        for (int l = 0; l < 26; l++){
          if (l != s[j] - 'a'){
            pos[l].push_back(j);
          }
        }
      }
      vector<int> cnt(26, 0);
      string ans;
      for (int j = 0; j < n; j++){
        bool ok = true;
        vector<int> cnt2 = cnt;
        cnt2[s[j] - 'a']++;
        int sum = 0;
        for (int l = 0; l < 26; l++){
          sum += (cnt2[l] + k - 1) / k * k;
        }
        if (sum > n){
          ok = false;
        } else {
          vector<int> rem(26);
          int sum2 = n - 1 - j;
          for (int l = 0; l < 26; l++){
            rem[l] = (cnt2[l] + k - 1) / k * k - cnt2[l];
            sum2 -= rem[l];
          }
          rem[25] += sum2;
          int cpos = j + 1;
          for (int l = 25; l >= 0; l--){
            auto itr = lower_bound(pos[l].begin(), pos[l].end(), cpos);
            if (itr != pos[l].end()){
              if ((*itr) < cpos + rem[l]){
                int d = s[(*itr)] - 'a';
                if (d < l){
                  break;
                }
                if (d > l){
                  ok = false;
                  break;
                }
              }
            }
            cpos += rem[l];
          }
        }
        if (ok){
          ans += s[j];
          cnt[s[j] - 'a']++;
        } else {
          for (int l = s[j] - 'a' + 1; l < 26; l++){
            vector<int> cnt3 = cnt;
            cnt3[l]++;
            int sum2 = 0;
            for (int m = 0; m < 26; m++){
              sum2 += (cnt3[m] + k - 1) / k * k;
            }
            if (sum2 <= n){
              ans += (char) ('a' + l);
              vector<int> rem(26);
              int sum3 = n - 1 - j;
              for (int m = 0; m < 26; m++){
                rem[m] = (cnt3[m] + k - 1) / k * k - cnt3[m];
                sum3 -= rem[m];
              }
              rem[0] += sum3;
              for (int m = 0; m < 26; m++){
                ans += string(rem[m], (char) ('a' + m));
              }
              break;
            }
          }
          break;
        }
      }
      cout << ans << endl;
    }
  }
}