#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

long long a , b ,c;

void work() {
  cin >> a >> b >> c;
  cout << "First" << endl;

  int last = -1;

  for (int i = 0 ; i < 1000 ; ++ i ) {
    long long x;
    long long mx = max(a , max(b, c));
    long long mn = min(a , min(b, c));
    long long mid = a + b + c - mn - mx;

    long long diff = 2 * mx - mid - mn;
    if (mx + mn == mid * 2) diff = mx - mid;
    cout << diff << endl;

    cin >> x;
    if (x == -1) break;
    if (x == 1) a += diff;
    if (x == 2) b += diff;
    if (x == 3) c += diff;
  }
}

int main() {
  work();
}