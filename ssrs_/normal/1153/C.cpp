#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;
  if (N % 2 == 1 || s[0] == ')' || s[N - 1] == '('){
    cout << ":(" << endl;
  } else {
    s[0] = '(';
    s[N - 1] = ')';
    if (N == 2){
      cout << s << endl;
    } else {
      if (s[1] == ')' || s[N - 2] == '('){
        cout << ":(" << endl;
      } else {
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < N - 1; i++){
          if (s[i] == '('){
            a++;
          }
          if (s[i] == ')'){
            b++;
          }
          if (s[i] == '?'){
            c++;
          }
        }
        int x = (c + b - a) / 2;
        int y = (c - b + a) / 2;
        if (x < 0 || y < 0){
          cout << ":(" << endl;
        } else {
          int cnt = 0;
          for (int i = 1; i < N - 1; i++){
            if (s[i] == '?'){
              if (cnt < x){
                s[i] = '(';
                cnt++;
              } else {
                s[i] = ')';
              }
            }
          }
          int sum = 0;
          bool ok = true;
          for (int i = 1; i < N - 1; i++){
            if (s[i] == '('){
              sum++;
            }
            if (s[i] == ')'){
              sum--;
              if (sum < 0){
                ok = false;
              }
            }
          }
          if (!ok){
            cout << ":(" << endl;
          } else {
            cout << s << endl;
          }
        }
      }
    }
  }
}