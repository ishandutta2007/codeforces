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

void solve() {
  int n, m, i, j;
  cin >> n >> m >> i >> j;
  --i, --j;

  vector <int> dx = {0, 0, n - 1, n - 1};
  vector <int> dy = {0, m - 1, m - 1, 0};

  ll dist = 0;
  int ta, tb;

  for (int a = 0; a < 4; ++a) {
    for (int b = 0; b < 4; ++b) {
      ll r1 = abs(i - dx[a]) + abs(j - dy[a]);
      int r2 = abs(i - dx[b]) + abs(j - dy[b]);
      int r3 = abs(dx[b] - dx[a]) + abs(dy[b] - dy[a]);

      if (dist <= r1 + r2 + r3) {
        dist = r1 + r2 + r3;
        ta = a, tb = b;
      }
    }
  }
  int a = ta, b = tb;

  cout << dx[a] + 1 << " " << dy[a] + 1 << " " << dx[b] + 1 << " " << dy[b] + 1 << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }
}