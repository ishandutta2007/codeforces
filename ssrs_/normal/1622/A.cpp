#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2 && l3 % 2 == 0){
      cout << "YES" << endl;
    } else if (l2 == l3 && l1 % 2 == 0){
      cout << "YES" << endl;
    } else if (l3 == l1 && l2 % 2 == 0){
      cout << "YES" << endl;
    } else if (max({l1, l2, l3}) * 2 == l1 + l2 + l3){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } 
}