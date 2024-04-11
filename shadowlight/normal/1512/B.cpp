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
  int n;
  cin >> n;
  vector <string> res(n);
  int x1, y1, x2, y2;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      res[i] += c;
      if (c == '*') {
        ++cnt;
        if (cnt == 1) {
          x1 = i, y1 = j;
        } else {
          x2 = i, y2 = j;
        }
      }
    }
  }

  int xx = -1;
  int yy = -1;

  if (x1 == x2) {
    xx = (x1 ? 0 : 1);
    res[xx][y1] = '*';
    res[xx][y2] = '*';
  }
  if (y1 == y2) {
    yy = (y1 ? 0 : 1);
    res[x1][yy] = '*';
    res[x2][yy] = '*';
  }
  res[x1][y2] = '*';
  res[x2][y1] = '*';

  for (int i = 0; i < n; ++i) {
    cout << res[i] << "\n";
  }
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