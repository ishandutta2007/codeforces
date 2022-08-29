#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> cnt(10, 0);
    for (int j = 0; j < N; j++){
      cnt[s[j] - '0']++;
    }
    int ans = N;
    for (int j = 0; j < 10; j++){
      ans = min(ans, N - cnt[j]);
    }
    for (int j = 0; j < 10; j++){
      for (int k = 0; k < 10; k++){
        int cnt2 = 0;
        for (int l = 0; l < N; l++){
          if (cnt2 % 2 == 0){
            if (s[l] - '0' == j){
              cnt2++;
            }
          } else {
            if (s[l] - '0' == k){
              cnt2++;
            }
          }
        }
        if (cnt2 % 2 == 0){
          ans = min(ans, N - cnt2);
        } else {
          ans = min(ans, N - cnt2 + 1);
        }
      }
    }
    cout << ans << endl;
  }
}