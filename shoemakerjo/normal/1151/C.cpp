#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
using ll = long long;
ll l, r;

ll mult(ll a, ll b) {
  return (a%mod)*(b%mod)%mod;
}

void add(ll &a, ll b) {
  a = (a + mod + b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> l >> r;

  ll ntake = 1; //how many are we taking
  bool even = false; //we start out taking evens

  ll res = 0LL;
  ll tottake = 0;

  ll egone = 0LL;
  ll ogone = 0LL;

  while (tottake < r) {

    // cout << "thing: " << res << endl;

    ll cstart = tottake + 1LL;
    ll cend = cstart + ntake - 1LL;

    // cout << cstart << " to " << cend << endl;

    if (cend >= l) {
      ll tstart = max(l, cstart);
      ll tend = min(r, cend);

      //take from this range
      ll cv = egone;
      if (!even) cv = ogone;
      ll sval = tstart - cstart + 1LL + cv;
      ll eval = tend - cstart + 1LL + cv;

      if (even) {
        ll cadd = mult(eval, eval+1);
        add(cadd, 0-mult(sval-1, sval));
        add(res, cadd);
      }
      else {
        ll cadd = mult(eval, eval);
        add(cadd, 0-mult(sval-1, sval-1));

        // cout << tottake << " -- " << cadd << endl;

        add(res, cadd);
      }
    }

    tottake += ntake;
    if (even) egone += ntake;
    else ogone += ntake;
    ntake *= 2LL;
    even = !even;
  }
  cout << res << endl;

}