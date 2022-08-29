#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    int r = x % 11;
    if (x >= r * 111){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}