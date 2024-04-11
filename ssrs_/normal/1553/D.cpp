#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool ok = false;
    for (int j = 0; j < 2; j++){
      int N = s.size();
      string s2;
      for (int k = 0; k < N; k++){
        if (s2.size() > t.size()){
          s2.pop_back();
        } else if (s2.empty()){
          s2 += s[k];
        } else if (s2.back() == t[s2.size() - 1]){
          s2 += s[k];
        } else {
          s2.pop_back();
        }
      }
      if (s2 == t){
        ok = true;
      }
      if (j == 0){
        s.erase(s.begin());
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}