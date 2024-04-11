#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x1;
    int p1;
    cin >> x1 >> p1;
    long long x2;
    int p2;
    cin >> x2 >> p2;
    int m = min(p1, p2);
    p1 -= m;
    p2 -= m;
    if (p1 >= 7){
      cout << '>' << endl;
    } else if (p2 >= 7){
      cout << '<' << endl;
    } else {
      for (int j = 0; j < p1; j++){
        x1 *= 10;
      }
      for (int j = 0; j < p2; j++){
        x2 *= 10;
      }
      if (x1 > x2){
        cout << '>' << endl;
      } else if (x1 < x2){
        cout << '<' << endl;
      } else {
        cout << '=' << endl;
      }
    }
  }
}