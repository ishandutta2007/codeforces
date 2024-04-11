#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    int R = 0, S = 0, P = 0;
    for (int j = 0; j < N; j++){
      if (s[j] == 'R'){
        R++;
      }
      if (s[j] == 'S'){
        S++;
      }
      if (s[j] == 'P'){
        P++;
      }
    }
    char c;
    if (R >= S && R >= P){
      c = 'P';
    } else if (S >= R && S >= P){
      c = 'R';
    } else {
      c = 'S';
    }
    for (int j = 0; j < N; j++){
      cout << c;
    }
    cout << endl;
  }
}