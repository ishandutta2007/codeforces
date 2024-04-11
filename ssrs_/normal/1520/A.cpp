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
    vector<bool> used(26, false);
    used[s[0] - 'A'] = true;
    bool ok = true;
    for (int j = 1; j < n; j++){
      if (s[j] != s[j - 1] && used[s[j] - 'A']){
        ok = false;
      }
      used[s[j] - 'A'] = true;
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}