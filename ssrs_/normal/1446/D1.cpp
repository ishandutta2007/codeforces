#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]]++;
  }
  int mx = 0;
  int mo = 0;
  for (auto P : mp){
    if (P.second > mx){
      mx = P.second;
      mo = P.first;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 100; i++){
    if (i != mo){
      vector<int> s(n);
      for (int j = 0; j < n; j++){
        if (a[j] == mo){
          s[j] = 1;
        } else if (a[j] == i){
          s[j] = -1;
        } else {
          s[j] = 0;
        }
      }
      vector<int> S(n + 1);
      S[0] = 0;
      for (int j = 0; j < n; j++){
        S[j + 1] = S[j] + s[j];
      }
      vector<int> L(n * 2 + 1, -1);
      for (int j = 0; j <= n; j++){
        if (L[S[j] + n] == -1){
          L[S[j] + n] = j;
        } else {
          ans = max(ans, j - L[S[j] + n]);
        }
      }
    }
  }
  cout << ans << endl;
}