#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    if (n == 1){
      cout << 0 << endl;
    } else if (n == 2){
      cout << m << endl;
    } else {
      cout << m * 2 << endl;
    }
  }
}