#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const ll INF = 1e18;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector <pair<ll, ll>> a(n);

  ll need = INF;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].y >> a[i].x;
    need = min(need, a[i].x);
  }
  sort(all(a));

  ll res = 0;
  int r = n - 1;
  ll bought = 0;
  for (int l = 0; l < n; ++l) {
    while (r >= l && bought < a[l].x) {
      ll val = min(a[l].x - bought, a[r].y);
      bought += val;
      res += 2 * val;
      a[r].y -= val;
      if (bought == a[l].x) {
        break;
      }
      --r;
    }
    bought += a[l].y;
    res += a[l].y;
  }

  cout << res << "\n";
}