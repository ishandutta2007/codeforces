#include <bits/stdc++.h>
using namespace std;
int main(){
  long long k;
  cin >> k;
  int L = 10;
  while (1){
    long long tmp = 1;
    for (int i = 0; i < 10; i++){
      if (i < L % 10){
        tmp *= (L / 10) + 1;
      } else {
        tmp *= (L / 10);
      }
    }
    if (tmp >= k){
      break;
    }
    L++;
  }
  string S = "codeforces";
  for (int i = 0; i < 10; i++){
    int t;
    if (i < L % 10){
      t = L / 10 + 1;
    } else {
      t = L / 10;
    }
    for (int j = 0; j < t; j++){
      cout << S[i];
    }
  }
  cout << endl;
}