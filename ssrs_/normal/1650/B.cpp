#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r, a;
    cin >> l >> r >> a;
    if (l / a == r / a){
      cout << r / a + r % a << endl;
    } else {
      int x = ((r + 1) / a - 1) * a + (a - 1);
      cout << max(x / a + x % a, r / a + r % a) << endl;
    }
  }
}