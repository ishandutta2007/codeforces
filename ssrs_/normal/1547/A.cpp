#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int xA, yA;
    cin >> xA >> yA;
    int xB, yB;
    cin >> xB >> yB;
    int xF, yF;
    cin >> xF >> yF;
    if (xA != xB && yA != yB){
      cout << abs(xB - xA) + abs(yB - yA) << endl;
    } else {
      if (xA == xB){
        swap(xA, yA);
        swap(xB, yB);
        swap(xF, yF);
      }
      if (yA != yF){
        cout << abs(xB - xA) << endl;
      } else {
        if (xA > xB){
          swap(xA, xB);
        }
        if (xA < xF && xF < xB){
          cout << xB - xA + 2 << endl;
        } else {
          cout << xB - xA << endl;
        }
      }
    }
  }
}