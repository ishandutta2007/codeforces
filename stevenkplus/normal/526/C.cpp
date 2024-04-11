#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll C, hr, hb, wr, wb;

int main() {
  cin >> C >> hr >> hb >> wr >> wb;

  if (wr > wb) {
    swap(wr, wb);
    swap(hr, hb);
  }

  ll ans = 0;
  ll wt = wr * wb;
  ll val = wb * hr;
  if (wr * hb > val) {
    val = wr * hb;
  }
  ll times = C / wt - 1;
  if (times < 0) times = 0;
  C -= times * wt;
  ans += times * val;

  ll mx = 0;
  for(int i = 0; i <= C / wb; ++i) {
    ll wt = C - i * wb;
    ll times = wt / wr;
    ll val = times * hr + i * hb;
    if (val > mx) mx = val;
  }

  cout << ans + mx << "\n";

}