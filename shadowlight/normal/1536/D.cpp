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

  set <int> q;

  int x;
  cin >> x;
  q.insert(x);
  int now = x;

  bool can = true;

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    if (x == now) {
      continue;
    }

    if (x > now) {
      auto it = q.upper_bound(now);
      if (it != q.end() && *it < x) {
        can = false;
      }
    } else {
      auto it = q.lower_bound(now);
      if (it != q.begin() && *(--it) > x) {
        can = false;
      }
    }
   /* cout << "SET: ";
    for (auto t : q) {
      cout << t << " ";
    }
    cout << "\n";
    cout << now << " " << x << " " << can << endl;*/

    q.insert(x);
    now = x;
  }
  cout << (can ? "YES\n" : "NO\n");

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