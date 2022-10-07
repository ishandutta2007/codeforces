#include <iostream>
using namespace std;

const int MOD = 998244353;
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  ll r = 1;
  for(int i = 0; i < n + m; ++i) {
    r = r * 2 % MOD;
  }
  cout << r << "\n";
}