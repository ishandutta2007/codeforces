#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    int ans = 0;
    for (int j = 0; j < 5; j++){
      vector<int> cnt(n, 0);
      for (int k = 0; k < n; k++){
        int L = s[k].size();
        for (int l = 0; l < L; l++){
          if (s[k][l] - 'a' == j){
            cnt[k]++;
          } else {
            cnt[k]--;
          }
        }
      }
      sort(cnt.begin(), cnt.end(), greater<int>());
      int S = 0;
      for (int k = 0; k < n; k++){
        S += cnt[k];
        if (S > 0){
          ans = max(ans, k + 1);
        }
      }
    }
    cout << ans << endl;
  }
}