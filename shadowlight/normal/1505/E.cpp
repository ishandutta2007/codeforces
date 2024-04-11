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



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;

  cin >> n >> m;
  vector <vector <bool>> a(n, vector<bool> (m, false));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '*') {
        a[i][j] = true;
      }
    }
  }

  int x = 0, y = 0;
  int cnt = a[0][0];
  while (x != n - 1 || y != m - 1) {
    if (y < m - 1 && a[x][y + 1]) {
      ++cnt;
      ++y;
    } else if (x < n - 1 && a[x + 1][y]) {
      ++cnt;
      ++x;
    } else if (y < m - 1) {
      ++y;
    } else {
      ++x;
    }
    //cout << x << " " << y << endl;
  }

  cout << cnt << endl;

}