#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string x;
    cin >> x;
    bool flg = false; //different flag
    string a, b;
    for (int j = 0; j < n; j++){
      if (x[j] == '0'){
        a += '0';
        b += '0';
      } else if (x[j] == '1' && !flg){
        a += '0';
        b += '1';
        flg = true;
      } else if (x[j] == '2' && !flg){
        a += '1';
        b += '1';
      } else {
        a += x[j];
        b += '0';
      }
    }
    cout << a << endl;
    cout << b << endl;
  }
}