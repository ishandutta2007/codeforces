#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    //a=r+1
    if (l % (r + 1) * 2 >= r + 1){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}