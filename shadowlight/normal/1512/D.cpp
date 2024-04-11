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

  ll sum = 0;
  map <ll, int> pos;

  vector <int> b(n + 2);

  for (int i = 0; i < n + 2; ++i) {
    cin >> b[i];
    sum += b[i];
    pos[b[i]] = i;
  }

  for (int i = 0; i < n + 2; ++i) {
    int x = b[i];
    if ((sum - x) % 2) continue;
    ll d = (sum - x) / 2;
    if (!pos.count(d)) continue;
    int j = pos[d];
    if (i == j) continue;
    for (int k = 0; k < n + 2; ++k) {
      if (k == i || k == j) continue;
      cout << b[k] << " ";
    }
    cout << "\n";
    return;
  }
  cout << "-1\n";
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