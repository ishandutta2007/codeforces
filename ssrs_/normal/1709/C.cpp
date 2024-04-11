#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> S(N + 1);
    S[0] = 0;
    for (int j = 0; j < N; j++){
      S[j + 1] = S[j];
      if (s[j] == '(' || s[j] == '?'){
        S[j + 1]++;
      } else {
        S[j + 1]--;
      }
    }
    int x = S[N] / 2;
    int cnt = 0;
    for (int j = N - 1; j >= 0; j--){
      if (s[j] == '?'){
        if (cnt < S[N] / 2 - 1 || cnt == S[N] / 2){
          s[j] = ')';
        } else {
          s[j] = '(';
        }
        cnt++;
      }
    }
    if (cnt < 2 || cnt == S[N] / 2){
      cout << "YES" << endl;
    } else {
      int sum = 0;
      bool ok = true;
      for (int j = 0; j < N; j++){
        if (s[j] == '('){
          sum++;
        }
        if (s[j] == ')'){
          sum--;
        }
        if (sum < 0){
          ok = false;
        }
      }
      if (!ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}