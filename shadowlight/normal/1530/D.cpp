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

  set <int> q, qq;
  for (int i = 0; i < n; ++i) {
    q.insert(i);
    qq.insert(i);
  }

  vector <int> who(n, -1);
  vector <int> res(n, -1);
  vector <int> tt(n);
  int opt = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    tt[i] = x;
    if (who[x] == -1) {
      who[x] = i;
      res[i] = x;
      q.erase(i);
      qq.erase(x);
      ++opt;
    }
  }

  while (q.size() > 2) {
    int x = *q.begin();
    auto it = qq.begin();
    if (x == *it) {
      ++it;
    }
    res[x] = *it;
    q.erase(x);
    qq.erase(it);
  }

  if (q.size() == 1) {
    int a = *q.begin();
    int b = *qq.begin();
    if (a != b) {
      res[a] = b;
    } else {
      //cout << a << " " << tt[a] << " " << who[tt[a]] << endl;
      res[a] = tt[a];
      res[who[tt[a]]] = b;
    }
  } else if (q.size()) {
    assert(q.size() == 2);
    int a = *q.begin(), b = *qq.begin();
    int c = *q.rbegin(), d = *qq.rbegin();

    if (a == b || c == d) {
      res[a] = d;
      res[c] = b;
    } else {
      res[a] = b;
      res[c] = d;
    }
  }

  cout << opt << "\n";
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << "\n";
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