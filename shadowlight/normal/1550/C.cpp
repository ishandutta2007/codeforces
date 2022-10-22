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

  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    for (int sz = 1; sz < 5; ++sz) {
      vector<int> b;
      for (int j = 0; j < sz; ++j) {
        if (i + j >= n) break;
        b.pb(a[i + j]); 
      }
      if (b.size() != sz) break;
      
      bool good = true;
      for (int x = 0; x < sz; ++x) {
        for (int y = x + 1; y < sz; ++y) {
          for (int z = y + 1; z < sz; ++z) {
            if (b[x] >= b[y] && b[y] >= b[z]) {
              good = false;
            }
            if (b[x] <= b[y] && b[y] <= b[z]) {
              good = false;
            }
          }
        }
      }
      res += good;
    }
  }

  cout << res << "\n";
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