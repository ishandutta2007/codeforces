#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n,x,y;
    cin >> n >> x >> y;
    int m,M;
    if (x + y <= n){
      cout << 1 << ' ' << x + y - 1 << endl;
    } else if (x + y < n * 2){
      cout << x + y - n + 1 << ' ' << n << endl;
    } else {
      cout << n << ' ' << n << endl;
    }
  }
}