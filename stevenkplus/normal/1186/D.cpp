#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> vals(n);
  vector<bool> can(n);
  long long tot = 0;
  for(int i = 0; i < n; ++i) {
    long double d;
    cin >> d;
    int sign = d > 0 ? 1 : -1;
    // printf("%Lf\n", d * 100000 + .5 * sign);
    long long k = (d * 100000 + .5 * sign);
    int val = k / 100000;
    if (val * 100000ll != k) {
      can[i] = true;
      // printf("can[%d] = %d\n", i, int(can[i]));
    }
    if (can[i] && k < 0) {
      --val;
    }
    vals[i] = val;
    tot += val;
  }
  int need = -tot;

  for(int i = 0; i < n; ++i) {
    int k = vals[i];
    if (can[i] && need) {
      ++k;
      --need;
    }
    cout << k << "\n";
  }
}