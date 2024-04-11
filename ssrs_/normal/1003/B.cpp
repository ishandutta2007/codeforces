#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, x;
  cin >> a >> b >> x;
  string s;
  int a2 = a, b2 = b;
  for (int i = 0; i <= x; i++){
    if (i % 2 == 0){
      s += '0';
      a2--;
    } else {
      s += '1';
      b2--;
    }
  }
  if (a2 < 0 || b2 < 0){
    s = "";
    a2 = a, b2 = b;
    for (int i = 0; i <= x; i++){
      if (i % 2 == 0){
        s += '1';
        b2--;
      } else {
        s += '0';
        a2--;
      }
    }
  }
  if (s[0] == '0'){
    for (int i = 0; i < b2; i++){
      s.insert(s.begin() + 1, '1');
    }
    for (int i = 0; i < a2; i++){
      s.insert(s.begin() + 1, '0');
    }
  } else {
    for (int i = 0; i < a2; i++){
      s.insert(s.begin() + 1, '0');
    }
    for (int i = 0; i < b2; i++){
      s.insert(s.begin() + 1, '1');
    }
  }
  cout << s << endl;
}