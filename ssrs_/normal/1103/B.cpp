#include <bits/stdc++.h>
using namespace std;
int main(){
  while (true){
    string s;
    cin >> s;
    if (s == "end"){
      break;
    }
    cout << "? 0 1" << endl;
    char c;
    cin >> c;
    if (c == 'x'){
      cout << "! " << 1 << endl;
    } else {
      int curr = 1;
      while (true){
        cout << "? " << curr << ' ' << curr * 2 << endl;
        cin >> c;
        if (c == 'x'){
          break;
        }
        curr *= 2;
      }
      int tv = curr * 2, fv = curr;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        cout << "? " << curr << " " << mid << endl;
        cin >> c;
        if (c == 'x'){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      cout << "! " << tv << endl;
    }
  }
}