#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        cnt++;
        ans = max(ans, (j + 1) * 2);
        ans = max(ans, (n - j) * 2);
      }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
  }
}