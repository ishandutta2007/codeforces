#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    vector<int> cnt(26, 0);
    for (int j = 0; j < n; j++){
      cnt[s[j] - 'a']++;
    }
    vector<char> t(m, '?');
    for (int j = 25; j >= 0; j--){
      vector<int> pos;
      for (int k = 0; k < m; k++){
        if (t[k] == '?'){
          int sum = 0;
          for (int l = 0; l < m; l++){
            if (t[l] != '?' && t[l] > 'a' + j){
              sum += abs(l - k);
            }
          }
          if (sum == b[k]){
            pos.push_back(k);
          }
        }
      }
      if (pos.size() <= cnt[j]){
        for (int k : pos){
          t[k] = 'a' + j;
        }
      }
    }
    for (int j = 0; j < m; j++){
      cout << t[j];
    }
    cout << endl;
  }
}