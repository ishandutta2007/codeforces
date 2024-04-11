#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string S;
    cin >> S;
    string T;
    cin >> T;
    int N = S.size();
    sort(S.begin(), S.end());
    bool ok = true;
    if (T == "abc"){
      int p = 0;
      for (int j = 0; j < N; j++){
        if (p < 3){
          if (S[j] == T[p]){
            p++;
          }
        }
      }
      if (p == 3){
        ok = false;
      }
    }
    if (ok){
      cout << S << endl;
    } else {
      auto itr1 = lower_bound(S.begin(), S.end(), 'b');
      auto itr2 = lower_bound(S.begin(), S.end(), 'c');
      auto itr3 = lower_bound(S.begin(), S.end(), 'd');
      rotate(itr1, itr2, itr3);
      cout << S << endl;
    }
  }
}