#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1){
    cout << "Yes" << endl;
  } else {
    vector<int> cnt(26);
    for (int i = 0; i < n; i++){
      cnt[s[i] - 'a']++;
    }
    bool ok = false;
    for (int i = 0; i < 26; i++){
      if (cnt[i] >= 2){
        ok = true;
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}