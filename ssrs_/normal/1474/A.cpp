#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string b;
    cin >> b;
    string a;
    int p = -1;
    for (int j = 0; j < n; j++){
      int x = b[j] - '0';
      if (p != x + 1){
        a += '1';
        p = x + 1;
      } else {
        a += '0';
        p = x;
      }
    }
    cout << a << endl;
  }
}