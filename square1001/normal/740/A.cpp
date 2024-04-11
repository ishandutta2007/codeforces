#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  long long ret = 1LL << 60;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        if((n + i + 2 * j + 3 * k) % 4 == 0) {
          ret = min(ret, a * i + b * j + c * k);
        }
      }
    }
  }
  cout << ret << endl;
  return 0;
}