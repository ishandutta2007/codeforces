#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    if (x > 45){
      cout << -1 << endl;
    } else {
      string s;
      int next = 9;
      while (x > 0){
        if (x >= next){
          s += '0' + next;
          x -= next;
          next--;
        } else {
          s += '0' + x;
          break;
        }
      }
      reverse(s.begin(), s.end());
      cout << s << endl;
    }
  }
}