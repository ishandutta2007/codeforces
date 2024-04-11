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
    string ans;
    for (int j = 0; j < k; j++){
      int p = 0;
      for (int l = 0; l < 26; l++){
        if (cnt[l] == 0 || p == n / k){
          ans += 'a' + l;
          break;
        } else {
          cnt[l]--;
          p++;
        }
      }
    }
    cout << ans << endl;
  }
}