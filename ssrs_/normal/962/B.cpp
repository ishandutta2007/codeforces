#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b;
  cin >> n >> a >> b;
  string S;
  cin >> S;
  int c = 0;
  vector<int> L;
  for (int i = 0; i < n; i++){
    if (S[i] == '.'){
      c++;
    } else {
      if (c != 0){
        L.push_back(c);
      }
      c = 0;
    }
  }
  if (c != 0){
    L.push_back(c);
  }
  int T = 0; //total
  for (int i : L){
    T += i;
  }
  int M = 0, m = 0;
  for (int i : L){
    M += (i + 1) / 2;
    m += i / 2;
  }
  if (a > b){
    swap(a, b);
  }
  if (a < m){
    cout << a + min(M, b) << endl;
  } else if (a < M){
    cout << a + min(M - (a - m), b) << endl;
  } else {
    cout << M + min(b, m) << endl;
  }
}