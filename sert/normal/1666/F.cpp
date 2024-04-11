#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MD = 998244353;
void add(int &a, int b) {
  a += b;
  if (a >= MD) {
    a -= MD;
  }
}

#ifdef SERT
using ARR = array<int, 9>;
#else
using ARR = array<int, 5002>;
#endif

ll pow_(ll x, ll deg) {
  if (deg == 0) return 1;
  if (deg % 2) return pow_(x, deg - 1) * x % MD;
  ll q = pow_(x, deg / 2);
  return q * q % MD;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll num = 1, dv = 1, lst = -1;
  vector<ll> fac(n + 2, 1);
  for (int i = 1; i < static_cast<int>(fac.size()); i++) fac[i] = fac[i - 1] * i % MD;
  for (int &x : a) {
    cin >> x;
    if (x == lst) { num++; }
    else { dv = (dv * fac[num] % MD); num = 1; lst = x;}
  }
  dv = (dv * num % MD);
  array<ARR, 2> dp{};
  ARR ad{};
  ARR first_pos{};
  ARR amount{};
  first_pos.fill(-1);

  for (int i = 0; i < n; i++) {
    amount[a[i]]++;
    if (first_pos[a[i]] == -1) {
      first_pos[a[i]] = i;
    }
    add(dp[1][a[i]], first_pos[a[i]]);
  }

//  cout << "2: ";
//  for (int val = 1; val <= n; val++) cout << setw(2) << dp[1][val] << " ";
//  cout << "\n";

  for (int h = 1; h < n / 2; h++) {
    ad.fill(0);
    for (int val = 1; val <= n; val++) {
      ll curDP = dp[h % 2][val];
      if (curDP == 0) continue;
      int extra = first_pos[val] - h * 2 + 1;
      if (extra > 0) {
        add(ad[val + 1], static_cast<int>(curDP * extra % MD));
      }
    }

    int tot_add = 0;
    dp[1 - h % 2].fill(0);
    //cout << h*2+2 << ": ";
    for (int val = 1; val <= n; val++) {
      add(tot_add, ad[val]);
      if (first_pos[val] == -1) { continue; }
      dp[1 - h % 2][val] = static_cast<int>(static_cast<ll>(tot_add) * amount[val] % MD);
      //cout << setw(2) << tot_add * amount[val] << " ";
    }
    //cout << "\n";
  }

  int ans = 0;
  for (int x : dp[(n / 2) % 2]) {
    add(ans, x);
  }
  cout << ans * pow_(dv, MD - 2) % MD << "\n";
}

int main() {
  cout.precision(3);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  freopen("../a.in", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t --> 0) {
    solve();
  }
}