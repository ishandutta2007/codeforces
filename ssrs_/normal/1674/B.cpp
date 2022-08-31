#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<string> S;
  for (int i = 0; i < 26; i++){
    for (int j = 0; j < 26; j++){
      if (i != j){
        string s;
        s += 'a' + i;
        s += 'a' + j;
        S.push_back(s);
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    for (int j = 0; j < 650; j++){
      if (S[j] == s){
        cout << j + 1 << endl;
      }
    }
  }
}