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
  int n, l, r;
  cin >> n >> l >> r;

  map <int, int> cnt[2];

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[i >= l][x]++;
    //cout << (i < l) << " " << x << endl;
  }

  int res = 0;
  for (auto t : cnt[0]) {
    int c = t.x;

    int w = min(cnt[0][c], cnt[1][c]);
    cnt[0][c] -= w;
    cnt[1][c] -= w;

    l -= w, r -= w;
  }

  int val = (l < r);

  for (auto t : cnt[val]) {
    int c = t.x;
    int dd = min(cnt[val][c] / 2, abs(r - l) / 2);
    //cout << val << " " << cnt[val][c] << " " << abs(r - l) / 2 << endl;

    res += dd;
    cnt[val][c] -= dd;
    cnt[1 - val][c] += dd;

    if (r > l) {
      r -= dd, l += dd;
    } else {
      l -= dd, r += dd;
    }
  }

  for (auto t : cnt[0]) {
    int c = t.x;

    int w = min(cnt[0][c], cnt[1][c]);
    cnt[0][c] -= w;
    cnt[1][c] -= w;

    l -= w, r -= w;
  }

  res += min(l, r);
  res += abs(r - l);

  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}