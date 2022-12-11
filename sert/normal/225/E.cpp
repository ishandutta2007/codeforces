#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;

ll pow2(ll step) {
  if (step == 0) return 1;
  if (step % 2) return pow2(step - 1) * 2 % MD;
  ll q = pow2(step / 2);
  return q * q % MD;
}

void solve() {
  vector<int> v = {1,2,4,6,12,16,18,30,60,88,106,126,520,606,1278,2202,2280,3216,4252,4422,9688,9940,11212,19936,21700,23208,44496,86242,110502,132048,216090,756838,859432,1257786,1398268,2976220,3021376,6972592,13466916,20996010};
  int n;
  cin >> n;
  cout << (pow2(v[n - 1]) + MD - 1) % MD << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 7;
#endif

  for (int i = 0; i < t; i++)
    solve();
}