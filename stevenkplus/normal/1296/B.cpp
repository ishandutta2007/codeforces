#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int N;
    cin >> N;
    int ans = 0;
    while (N > 0) {
      int x = 1;
      while (x * 10 <= N) x *= 10;
      N -= x;
      ans += x;
      N += x / 10;
    }
    cout << ans << "\n";
  }
}