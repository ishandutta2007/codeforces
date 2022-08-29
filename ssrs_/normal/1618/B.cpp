#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for (int j = 0; j < n - 2; j++){
      cin >> s[j];
    }
    string ans = s[0];
    bool used = false;
    for (int j = 1; j < n - 2; j++){
      if (ans.back() == s[j][0]){
        ans += s[j][1];
      } else {
        used = true;
        ans += s[j];
      }
    }
    if (!used){
      ans += 'a';
    }
    cout << ans << endl;
  }
}