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
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j];
      if (s[j] == 'W'){
        S[j + 1]++;
      }
    }
    int ans = n;
    for (int j = 0; j <= n - k; j++){
      ans = min(ans, S[j + k] - S[j]);
    }
    cout << ans << endl;
  }
}