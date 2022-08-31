#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  string s;
  cin >> s;
  if (x == 12){
    if (s[3] >= '6'){
      s[3] = '0';
    }
    if (s[0] >= '2'){
      if (s[1] == '0'){
        s[0] = '1';
      } else {
        s[0] = '0';
      }
    }
    if (s[0] == '1' && s[1] >= '3'){
      s[1] = '0';
    }
    if (s[0] == '0' && s[1] == '0'){
      s[0] = '1';
    }
    cout << s << endl;
  } else {
    if (s[3] >= '6'){
      s[3] = '0';
    }
    if (s[0] >= '3' || s[0] == '2' && s[1] >= '4'){
      s[0] = '0';
    }
    cout << s << endl;
  }
}