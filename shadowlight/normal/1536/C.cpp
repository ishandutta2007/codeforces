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

  string s;
  cin >> s;

  int a = 0, b = 0;

  vector <int> res(n, 0);
  vector<map<int, int>> last(n + 1);

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'D') {
      ++a;
    } else {
      ++b;
    }
    int g = __gcd(a, b);
    int aa = a, bb = b;
    a /= g, b /= g;

    if (last[a].count(b)) {
      res[i] = res[last[a][b]] + 1;
    } else {
      res[i] = 1;
    }
    last[a][b] = i;
    cout << res[i] << " ";
    a = aa, b = bb;
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}