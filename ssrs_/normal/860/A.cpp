#include <bits/stdc++.h>
using namespace std;
bool is_consonant(char c){
  return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}
int main(){
  string S;
  cin >> S;
  int N = S.size();
  string ans;
  int L = 0, R = 0;
  while (L < N){
    if (L > 0){
      ans += ' ';
    }
    while (R < N){
      bool ok;
      int R2 = R + 1;
      if (R2 - L < 3){
        ok = true;
      } else {
        string T = S.substr(R2 - 3, 3);
        if (is_consonant(T[0]) && is_consonant(T[1]) && is_consonant(T[2]) && !(T[0] == T[1] && T[1] == T[2])){
          ok = false;
        } else {
          ok = true;
        }
      }
      if (ok){
        R++;
      } else {
        break;
      }
    }
    ans += S.substr(L, R - L);
    L = R;
  }
  cout << ans << endl;
}