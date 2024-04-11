#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

ll dp[11][65][1 << 10];

ll calc(int b, ll r) {
  r++;
  vector<int> c;
  while (r > 0) {
    c.pb(int(r % b));
    r /= b;
  }  
  ll ans = 0;
  int msk = 0;  
  for (int i = sz(c) - 1; i >= 0; i--) {
    for (int j = 0; j < c[i]; j++) {
      if (j == 0 && i + 1 == sz(c)) {
        continue;
      }
      ans += dp[b][i][msk ^ (1 << j)];
    }
    msk ^= (1 << c[i]);
  }
  for (int i = sz(c) - 2; i >= 0; i--) {
    for (int j = 1; j < b; j++) {
      ans += dp[b][i][(1 << j)];
    }
  }
  return ans;
}

void solve2() {
  int b;
  ll l, r;
  cin >> b >> l >> r;
  cout << calc(b, r) - calc(b, l - 1) << endl;
}

void precalc() {
  for (int b = 2; b <= 10; b++) {
    dp[b][0][0] = 1ll;
    for (int j = 1; j <= 64; j++) {
      for (int msk = 0; msk < (1 << b); msk++) {
        for (int c = 0; c < b; c++) {
          dp[b][j][msk] += dp[b][j - 1][msk ^ (1 << c)];
        }
      }
    }
  }
}

void solve() {
  precalc();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    solve2();
  }
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}