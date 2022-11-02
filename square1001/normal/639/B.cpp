#include <bits/stdc++.h>
using namespace std;
int n, d, h;
int main() {
  cin >> n >> d >> h;
  if(h * 2 < d || (n != 2 && d == 1)) cout << -1 << endl;
  else if(d == h) {
    for(int i = 1; i <= d; i++) cout << i << ' ' << i + 1 << endl;
    for(int i = d + 2; i <= n; i++) cout << d << ' ' << i << endl;
  }
  else {
    for(int i = 1; i <= h; i++) cout << i << ' ' << i + 1 << endl;
    cout << 1 << ' ' << h + 2 << endl;
    for(int i = 2; i <= d - h; i++) cout << h + i << ' ' << h + i + 1 << endl;
    for(int i = d + 2; i <= n; i++) cout << 1 << ' ' << i << endl;
  }
  return 0;
}