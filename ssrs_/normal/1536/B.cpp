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
    vector<string> t;
    for (int j = 0; j < 26; j++){
      t.push_back(string(1, 'a' + j));
    }
    for (int j = 0; j < 26; j++){
      for (int k = 0; k < 26; k++){
        t.push_back(string(1, 'a' + j) + string(1, 'a' + k));
      }
    }
    for (int j = 0; j < 26; j++){
      for (int k = 0; k < 26; k++){
        for (int l = 0; l < 26; l++){
          t.push_back(string(1, 'a' + j) + string(1, 'a' + k) + string(1, 'a' + l));
        }
      }
    }
    int cnt = t.size();
    for (int j = 0; j < cnt; j++){
      bool ok = false;
      int L = t[j].size();
      for (int k = 0; k <= n - L; k++){
        if (s.substr(k, L) == t[j]){
          ok = true;
        }
      }
      if (!ok){
        cout << t[j] << endl;
        break;
      }
    }
  }
}