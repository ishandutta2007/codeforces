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
    int k;
    cin >> k;
    vector<char> c(k);
    for (int j = 0; j < k; j++){
      cin >> c[j];
    }
    vector<bool> p(26, false);
    for (int j = 0; j < k; j++){
      p[c[j] - 'a'] = true;
    }
    int cnt = 0;
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (!p[s[j] - 'a']){
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
    cout << ans << endl;
  }
}