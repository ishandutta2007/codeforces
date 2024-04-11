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
  vector <int> a, b;
  vector <int> was(n, 0);
  set <int> q;
  for (int i = 0; i < n; ++i) {
    q.insert(i);
  }
  int pr = -1;
  int now = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    if (x != pr) {
      was[x] = true;
      a.pb(x);
      b.pb(x);
      q.erase(x);
      pr = x;
    } else {
      while (now < n && was[now]) {
        ++now;
      }
      auto it = q.lower_bound(pr);
      assert(it != q.begin());
      b.pb(*(--it));
      q.erase(it);
      was[now] = true;
      a.pb(now);
    }
  }
  for (int x : a) {
    cout << x + 1 << " ";
  }
  cout << "\n";
  for (int x : b) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}