#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string S;
  cin >> S;
  int N = 0;
  int t = 0;
  for (int i = 0; i < n; i++){
    if (S[i] == '('){
      N++;
      if (N == 0) t++;
    } else {
      N--;
    }
    if (N < 0) t++;
  }
  if (N != 0){
    cout << -1;
  } else {
    cout << t;
  }
}