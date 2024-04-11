#include <iostream>
using namespace std;
long long a, b, k;
long long p(long long x) {
  return x / k;
}
int main() {
  cin >> k >> a >> b;
  if (a > b) swap(a, b);
  if (a <= 0 && b < 0)
    cout << p(-a) - p(-b - 1);
  else if (a <= 0 && b >= 0)
    cout << p(-a) + p(b) + 1;
  else cout << p(b) - p(a - 1);
}