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

int inv(int a) {
  return bp(a, mod - 2);
}

const int N = 1e6 + 7;

int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(rf[k], rf[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int n;
  cin >> n;

  int res = 0;

  for (int x = 2; x <= n; x += 2) {
    if (x == n) {
      add(res, mult(2, f[x]));
      continue;
    }
    int now = C(x, n - x);
    add(now, C(x - 1, n - x - 1));
    now = mult(now, f[x]);
    now = mult(now, 2);

    add(res, now);
  }
  cout << res << "\n";
}