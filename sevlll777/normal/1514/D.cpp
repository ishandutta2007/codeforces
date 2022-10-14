#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = 300009;
int A[N], LF[N], ans[N], cnt[N], G[N];
int L = 1, R = 0;
int jo = 0;

void del(int i) {
  int num = A[i];
  if (G[cnt[num]] == 1) {
    if (jo == cnt[num]) {
      jo--;
    }
  }
  G[cnt[num]]--;
  cnt[num]--;
  G[cnt[num]]++;
}

void add(int i) {
  int num = A[i];
  G[cnt[num]]--;
  cnt[num]++;
  G[cnt[num]]++;
  jo = max(jo, cnt[num]);
}

void add_left() {
  add(L - 1);
  L--;
}

void add_right() {
  add(R + 1);
  R++;
}

void del_left() {
  del(L);
  L++;
}

void del_right() {
  del(R);
  R--;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<vector<int>> qu;
  int s = (int) sqrt(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    LF[i] = l;
    qu.pb({l / s, r, i});
  }
  sort(all(qu));
  for (auto p : qu) {
    int l = LF[p[2]], r = p[1];
    while (R > r) {
      del_right();
    }
    while (R < r) {
      add_right();
    }
    while (L > l) {
      add_left();
    }
    while (L < l) {
      del_left();
    }
    int sum = r - l + 1, mx = jo;
    ans[p[2]] = 1;
    int w = sum - mx + 1;
    mx -= w;
    if (mx > 0) {
      ans[p[2]] += mx;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }

}