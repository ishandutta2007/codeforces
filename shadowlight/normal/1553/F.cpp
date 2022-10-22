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

const int N = 3e5 + 7;
struct Tree {
  ll sum[4 * N];
  int cnt[4 * N];
  int cnt_lazy[4 * N];
  ll val_lazy[4 * N];

  Tree() {}

  void relax(int v) {
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1]; 
  }

  void add_lazy(int l, int r, ll x, int vt = 1, int lt = 0, int rt = N) {
    if (lt >= r || l >= rt) {
      return;
    }
    if (l <= lt && rt <= r) {
      cnt_lazy[vt]++;
      val_lazy[vt] -= x;
      return; 
    }
    int mt = (lt + rt) / 2;
    add_lazy(l, r, x, 2 * vt, lt, mt);
    add_lazy(l, r, x, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  pair<ll, int> get(int l, int r, int vt = 1, int lt = 0, int rt = N) {
    if (lt >= r || l >= rt) {
      return {0, 0};
    }
    if (l <= lt && rt <= r) {
      return {sum[vt], cnt[vt]};
    }
    int mt = (lt + rt) / 2;
    auto t1 = get(l, r, 2 * vt, lt, mt);
    auto t2 = get(l, r, 2 * vt + 1, mt, rt);
    relax(vt);

    return {t1.x + t2.x, t1.y + t2.y};
  }

  void insert(int x, int vt = 1, int lt = 0, int rt = N) {
    if (rt - lt == 1) {
      sum[vt] += x;
      cnt[vt] += 1;
      return;
    }
    int mt = (lt + rt) / 2;
    if (x < mt) {
      insert(x, 2 * vt, lt, mt);
    } else {
      insert(x, 2 * vt + 1, mt, rt);
    }
    relax(vt);
  }

  pair <int, ll> get_val(int x, int vt = 1, int lt = 0, int rt = N) {
    if (rt - lt == 1) {
      return {cnt_lazy[vt], val_lazy[vt]};
    }
    pair <int, ll> t;

    int mt = (lt + rt) / 2;
    if (x < mt) {
      t = get_val(x, 2 * vt, lt, mt);
    } else {
      t = get_val(x, 2 * vt + 1, mt, rt);
    }
    relax(vt);
    return {t.x + cnt_lazy[vt], t.y + val_lazy[vt]};
  }
} tree;



int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  ll res = 0;

  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;

    auto [sum1, cnt1] = tree.get(x + 1, N);
    res += cnt1 * x;

    auto [sum2, cnt2] = tree.get(0, x);
    res += sum2;

    auto [cntl, val] = tree.get_val(x);
    //cout << "POS: " << res << " " << cntl << " " << val << endl;
    res += cntl * x + val;


    for (ll l = x; l < N; l += x) {
      ll r = min((ll)N, l + x);
      
      auto [sum, cnt] = tree.get(l, r);
      res += sum - cnt * l;

      tree.add_lazy(l, r, l);
    }
    tree.insert(x);
  
    cout << res << " ";
  }
  cout << "\n";
}