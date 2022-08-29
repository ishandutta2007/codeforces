#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int a = 0, b = 1;
    for (int j = 2; j < n; j += 2){
      int x = j;
      int y = j + 1;
      vector<int> r(4);
      cout << "? " << a + 1 << ' ' << b + 1 << ' ' << x + 1 << endl;
      cin >> r[0];
      cout << "? " << a + 1 << ' ' << b + 1 << ' ' << y + 1 << endl;
      cin >> r[1];
      cout << "? " << a + 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
      cin >> r[2];
      cout << "? " << b + 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
      cin >> r[3];
      int mx = max({r[0], r[1], r[2], r[3]});
      int a2, b2;
      if (mx == r[0] && mx == r[1]){
        a2 = a;
        b2 = b;
      }
      if (mx == r[0] && mx == r[2]){
        a2 = a;
        b2 = x;
      }
      if (mx == r[0] && mx == r[3]){
        a2 = x;
        b2 = b;
      }
      if (mx == r[1] && mx == r[2]){
        a2 = a;
        b2 = y;
      }
      if (mx == r[1] && mx == r[3]){
        a2 = b;
        b2 = y;
      }
      if (mx == r[2] && mx == r[3]){
        a2 = x;
        b2 = y;
      }
      if (j != n - 3){
        a = a2;
        b = b2;
      } else {
        if (b2 != y){
          a = a2;
          b = b2;
        } else if (a2 != b){
          a = a2;
        }
        j--;
      }
    }
    cout << "! " << a + 1 << ' ' << b + 1 << endl;
  }
}