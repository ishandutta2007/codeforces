#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x0, n;
    cin >> x0 >> n;
    long long n2 = n / 4 * 4;
    while (n2 < n){
      if (x0 % 2 == 0){
        x0 -= n2 + 1;
      } else {
        x0 += n2 + 1;
      }
      n2++;
    }
    cout << x0 << endl;
  }
}