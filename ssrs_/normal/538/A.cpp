#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string T = "CODEFORCES";
  int N = S.size();
  if (N <= 10){
    cout << "NO" << endl;
  } else {
    bool ok = false;
    for (int i = 0; i <= 10; i++){
      string S2 = S.substr(0, i) + S.substr(N - (10 - i));
      if (S2 == T){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}