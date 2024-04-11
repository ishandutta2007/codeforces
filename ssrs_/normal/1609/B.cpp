#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i <= n - 2; i++){
    if (s.substr(i, 3) == "abc"){
      ans++;
    }
  }
  for (int j = 0; j < q; j++){
    int i;
    char c;
    cin >> i >> c;
    i--;
    for (int k = max(i - 2, 0); k <= min(i, n - 2); k++){
      if (s.substr(k, 3) == "abc"){
        ans--;
      }
    }
    s[i] = c;
    for (int k = max(i - 2, 0); k <= min(i, n - 2); k++){
      if (s.substr(k, 3) == "abc"){
        ans++;
      }
    }
    cout << ans << "\n";
  }
}