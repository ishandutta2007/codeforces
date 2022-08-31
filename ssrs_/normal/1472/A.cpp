#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int w, h, n;
    cin >> w >> h >> n;
    if (n <= (1 << (__builtin_ctz(w) + __builtin_ctz(h)))){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}