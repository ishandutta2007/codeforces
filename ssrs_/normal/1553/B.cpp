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
    int N = s.size();
    int M = t.size();
    bool ok = false;
    for (int j = 0; j < N; j++){
      for (int k = j; k < N; k++){
        string s2;
        for (int l = j; l <= k; l++){
          s2 += s[l];
        }
        for (int l = k - 1; l >= 0; l--){
          s2 += s[l];
        }
        if (s2.size() >= t.size()){
          if (s2.substr(0, t.size()) == t){
            ok = true;
          }
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}