#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++){
    set<string> st;
    for (int j = 1; j <= 9; j++){
      for (int k = 0; k <= 9 - j; k++){
        st.insert(S[i].substr(k, j));
      }
    }
    for (string s : st){
      mp[s]++;
    }
  }
  for (int i = 0; i < n; i++){
    bool ok = false;
    for (int j = 1; j <= 9; j++){
      for (int k = 0; k <= 9 - j; k++){
        if (mp[S[i].substr(k, j)] == 1){
          cout << S[i].substr(k, j) << endl;
          ok = true;
          break;
        }
      }
      if (ok){
        break;
      }
    }
  }
}