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
  int n, m, x;
  cin >> n >> m >> x;

  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector <int> res(n, 0);
  set <pair <int, int>> values;
  for (int i = 0; i < m; ++i) {
    res[i] = i;
    values.insert({a[i], i});
  }
  for (int i = m; i < n; ++i) {
    auto t = *values.begin();
    int index = t.y;
    int sum = t.x;

    sum += a[i];
    res[i] = index;
    values.erase(t);
    values.insert({sum, index});
  }

  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << res[i] + 1 << " ";
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