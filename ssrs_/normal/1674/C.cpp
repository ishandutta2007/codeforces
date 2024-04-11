#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string s, t;
    cin >> s >> t;
    int N = s.size();
    int M = t.size();
    int as = 0;
    for (int j = 0; j < N; j++){
      if (s[j] == 'a'){
        as++;
      }
    }
    int at = 0;
    for (int j = 0; j < M; j++){
      if (t[j] == 'a'){
        at++;
      }
    }
    if (at > 0){
      if (t == "a"){
        cout << 1 << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      cout << (((long long) 1) << as) << endl;
    }
  }
}