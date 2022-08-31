#include <bits/stdc++.h>
using namespace std;
int main(){
  string S = "+";
  int n;
  while (1){
    string T;
    cin >> T;
    if (T == "+" || T == "-"){
      S += T;
    } else if (T == "="){
      cin >> n;
      break;
    }
  }
  int cnt = S.size();
  int add = 0, sub = 0;
  for (int i = 0; i < cnt; i++){
    if (S[i] == '+'){
      add++;
    }
    if (S[i] == '-'){
      sub--;
    }
  }
  vector<int> L(cnt + 1), R(cnt + 1);
  L[0] = 0;
  R[0] = 0;
  bool ok = true;
  for (int i = 0; i < cnt; i++){
    if (S[i] == '+'){
      L[i + 1] = L[i] + 1;
      R[i + 1] = R[i] + n;
    }
    if (S[i] == '-'){
      L[i + 1] = L[i] - n;
      R[i + 1] = R[i] - 1;
    }
  }
  if (R[cnt] < n || n < L[cnt]){
    cout << "Impossible" << endl;
  } else {
    vector<int> num(cnt);
    int value = n;
    for (int i = cnt - 1; i >= 0; i--){
      for (int j = 1; j <= n; j++){
        if (S[i] == '+'){
          if (L[i] <= value - j && value - j <= R[i]){
            num[i] = j;
            value -= j;
            break;
          }
        }
        if (S[i] == '-'){
          if (L[i] <= value + j && value + j <= R[i]){
            num[i] = j;
            value += j;
            break;
          }
        }
      }
    }
    cout << "Possible" << endl;
    for (int i = 0; i < cnt; i++){
      cout << num[i] << ' ';
      if (i < cnt - 1){
        cout << S[i + 1] << ' ';
      }
    }
    cout << "= " << n << endl;
  }
}