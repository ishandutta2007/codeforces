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

struct Tree {
  int n;
  vector <pair <int, int>> t;

  void build(vector<int>& a, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = {a[l], l};
      return;
    }
    int m = (l + r) / 2;
    build(a, 2 * v, l, m);
    build(a, 2 * v + 1, m, r);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }

  Tree(vector<int>& a, int n) : n(n), t(2 * n) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = {a[i], i};
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = min(t[2 * i], t[2 * i + 1]);
    }
  } 

  pair<int, int> get(int l, int r) {
    pair <int, int> res = {1e9 + 7, -1};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      //cout << l << " " << r << endl;
      if (l % 2 == 1) {
        res = min(res, t[l++]);
      }
      if (r % 2 == 0) {
        res = min(res, t[r--]);
      }
    }
    //cout << res.x << " " << res.y << endl;
    return res;
  }

  Tree() {}
};

Tree tree;
vector <int> b;
int n;

const ll INF = 1e9 + 7;

ll solve(int l, int r) {
  if (l == r) {
    return 0;
  }
  //cout << "SOLVE: " << l << " " << r << endl;
  int pos = tree.get(l, r - 1).y;
  assert(pos != -1);
  ll resl = solve(l, pos);
  ll resr = solve(pos + 1, r);

  ll res = -INF;
  res = max(res, resl + resr + b[pos]);
  if (l != 0) {
    res = max(res, resr);
  }
  if (r != n) {
    res = max(res, resl);
  }
  return res;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  vector <int> h(n); 
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  tree = Tree(h, n);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  cout << solve(0, n) << "\n";
}