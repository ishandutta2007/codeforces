#include <bits/stdc++.h>

using namespace std;

const long long L = 1ll << 32;

int main() {
  long long a, b, c;
  int who;
  cin >> a >> b >> c;
  cout << "First" << endl;
  cout << L << endl;
  cin >> who;
  if (who == 1) {
    a += L;
  } else if (who == 2) {
    b += L;
  } else if (who == 3) {
    c += L;
  } else {
    return 0;
  }
  long long d = 3 * max(max(a, b), c) - a - b - c;
  cout << d << endl;
  cin >> who;
  if (who == 1) {
    a += d;
  } else if (who == 2) {
    b += d;
  } else if (who == 3) {
    c += d;
  } else {
    return 0;
  }
  vector<long long> e = {a, b, c};
  sort(e.begin(), e.end());
  cout << e[1] - e[0] << endl;
  cin >> who;
  return 0;
}