#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> R(10, -1);
    for (int j = 0; j < N; j++){
      int c = s[j] - '0';
      R[c] = max(R[c], j);
    }
    vector<int> cnt(10, 0);
    string ans;
    int p = 0;
    for (int j = 0; j < 10; j++){
      if (R[j] != -1){
        while (p <= R[j]){
          if (s[p] - '0' == j){
            ans += s[p];
          } else {
            cnt[s[p] - '0']++;
          }
          p++;
        }
      }
      int c = '0' + min(j + 1, 9);
      ans += string(cnt[j], c);
    }
    cout << ans << endl;
  }
}