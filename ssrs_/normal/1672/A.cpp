#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int x = 0;
    for (int j = 0; j < n; j++){
      x += a[j] - 1;
    }
    if (x % 2 == 0){
      cout << "maomao90" << endl;
    } else {
      cout << "errorgorn" << endl;
    }
  }
}