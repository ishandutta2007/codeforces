#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string t;
    cin >> t;
    int N = t.size();
    int zero = 0;
    int one = 0;
    for (int j = 0; j < N; j++){
      if (t[j] == '0'){
        zero++;
      } else {
        one++;
      }
    }
    if (zero == 0 || one == 0){
      cout << t << endl;
    } else {
      for (int j = 0; j < N; j++){
        cout << "01";
      }
      cout << endl;
    }
  }
}