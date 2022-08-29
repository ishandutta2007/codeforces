#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        p.push_back(j);
      }
    }
    if (p.empty()){
      cout << 0 << endl;
    } else {
      int cnt = p.size();
      bool ok = true;
      for (int j = 0; j < cnt - 1; j++){
        if (p[j + 1] - p[j] != 1){
          ok = false;
        }
      }
      if (ok){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}