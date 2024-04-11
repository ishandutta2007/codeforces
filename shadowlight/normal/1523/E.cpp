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

int rev(int a) {
  return bp(a, mod - 2);
}

const int N = 1e5 + 7;

int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = rev(f[i]);
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(rf[k], rf[n - k]));
}


void solve() {
  int n, k;
  cin >> n >> k;

  vector <int> good(n + 1, 0);
  good[0] = 1;

  int mlt = 1;
  for (int cnt = 1; cnt <= n; ++cnt) {
    int total = (cnt - 1) * (k - 1) + cnt;
    int breakes = n - total;

    if (total > n) break;

    good[cnt] = mult(f[cnt], C(breakes + cnt, cnt));
  }

  int res = 0;
  for (int cnt = 1; cnt <= n; ++cnt) {
    mlt = mult(mlt, rev(n - cnt + 1));
    
    int bad = mult(good[cnt - 1], n - cnt + 1);
    add(bad, -good[cnt]);

    //cout << bad << " " << cnt << endl;
    add(res, mult(bad, mult(mlt, cnt)));
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}