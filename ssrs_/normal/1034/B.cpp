#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, m;
  cin >> n >> m;
  if (n > m){
    swap(n, m);
  }
  if (n == 1){
    int ans = m / 6 * 6;
    if (m % 6 == 4){
      ans += 2;
    }
    if (m % 6 == 5){
      ans += 4;
    }
    cout << ans << endl;
  } else if (n == 2){
    if (m <= 2){
      cout << 0 << endl;
    } else if (m == 3){
      cout << 4 << endl;
    } else if (m == 7){
      cout << 12 << endl;
    } else {
      cout << m * 2 << endl;
    }
  } else {
    cout << n * m / 2 * 2 << endl;
  }
}