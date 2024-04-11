#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        S[j + 1] = S[j] + 1;
      } else {
        S[j + 1] = S[j] - 1;
      }
    }
    int m = abs(S[n]);
    bool inf = false;
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (S[n] == 0){
        if (S[j] == x){
          inf = true;
        }
      } else {
        int r = (S[j] % m + m) % m;
        int x2 = (x % m + m) % m;
        if (x2 == r){
          if (x == S[j] || x > S[j] && S[n] > 0 || x < S[j] && S[n] < 0){
            ans++;
          }
        }
      }
    }
    if (inf){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}