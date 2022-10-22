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

int n, m;
vector <int> p;
bool check(int shift) {
  vector <int> need(n, 0);
  for (int i = 0; i < n; ++i) {
    need[i] = (i + shift);
    if (need[i] >= n) {
      need[i] -= n;
    }
  }
  vector <bool> used(n, 0);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int v = i;
    if (!used[v]) --cnt;
    while (!used[v]) {
      ++cnt;
      used[v] = true;
      //cout << "NEED: " << v << " " << p[v] << " " << need[p[v]] << endl;
      v = need[p[v]];
    }
  }
  //cout << shift << " " << cnt << " " << m << endl;
  return cnt <= m;
}

void solve() {
  cin >> n >> m;

  p.assign(n, 0);
  vector <int> pos(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }

  vector <int> counts(n, 0);

  for (int i = 0; i < n; ++i) {
    int delta = pos[i] - i;
    if (delta < 0) {
      delta += n;
    }
    ++counts[delta];
  }
  vector <int> res;
  for (int k = 0; k < n; ++k) {
    if (counts[k] < n / 3) continue; 
    if (check(k)) {
      res.pb(k);
    }
  }
  cout << res.size() << " ";
  for (int x : res) {
    cout << x << " ";
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