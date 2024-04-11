#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// ===================================================================

template<typename F>
void dpDCRec(ll const* d, ll *nd, F const& w, int l, int r, int sl, int sr) {
  if (l == r) return;
  int mid = (l + r) / 2;
  ll bestD = LINF;
  int bestS = sl;
  for (int i = sl; i < min(mid, sr); ++i) {
    ll cd = d[i] + w(i, mid);
    if (cd < bestD) {
      bestD = cd;
      bestS = i;
    }
  }
  nd[mid] = bestD;
  dpDCRec(d, nd, w, l, mid, sl, bestS + 1);
  dpDCRec(d, nd, w, mid + 1, r, bestS, sr);
}

template<typename F>
ll dpDC(int n, int k, F const& w) {
  assert(k <= n);
  vector<ll> d(n + 1, LINF);
  d[0] = 0;
  vector<ll> nd(n + 1);
  for (int iter = 0; iter < k; ++iter) {
    dpDCRec(d.data(), nd.data(), w, 0, n + 1, 0, n + 1);
    swap(d, nd);
  }
  return d[n];
}

template<typename F>
void dpAnsDCRec(pair<ll, int> const* d, pair<ll, int> *nd, F const& w, int l, int r, int sl, int sr) {
  if (l == r) return;
  int mid = (l + r) / 2;
  ll bestD = LINF;
  int bestS = sl;
  for (int i = sl; i < min(mid, sr); ++i) {
    ll cd = d[i].first + w(i, mid);
    if (cd < bestD) {
      bestD = cd;
      bestS = i;
    }
  }
  nd[mid] = {bestD, bestS};
  dpAnsDCRec(d, nd, w, l, mid, sl, bestS + 1);
  dpAnsDCRec(d, nd, w, mid + 1, r, bestS, sr);
}

template<typename F>
vector<int> dpAnsDC(int n, int k, F const& w) {
  assert(k <= n);
  vector<vector<pair<ll, int>>> d(k + 1, vector<pair<ll, int>>(n + 1, {LINF, -1}));
  d[0][0] = {0, -1};
  for (int iter = 0; iter < k; ++iter) {
    dpAnsDCRec(d[iter].data(), d[iter + 1].data(), w, 0, n + 1, 0, n + 1);
  }
  vector<int> ans = {n};
  int i = n;
  for (int j = k; j > 0; --j) {
    i = d[j][i].second;
    assert(i >= 0);
    ans.push_back(i);
  }
  reverse(all(ans));
  return ans;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<ll>> c(n + 1, vector<ll>(n + 1, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      ll x;
      char ch;
      do {
        ch = getchar();
      } while (!('0' <= ch && ch <= '9'));
      x = ch - '0';
      if (i < j) c[i][j + 1] += x;
    }

  for (int l = n; l >= 0; --l)
    for (int r = l; r <= n; ++r) {
      if (l < n) c[l][r] += c[l + 1][r];
      if (r > 0) c[l][r] += c[l][r - 1];
      if (l < n && r > 0) c[l][r] -= c[l + 1][r - 1];
    }

  ll ans = dpDC(n, k, [&](int x, int y) { return c[x][y]; });
  cout << ans << "\n";

  vector<int> ansI = dpAnsDC(n, k, [&](int x, int y) { return c[x][y]; });
  assert(sz(ansI) == k + 1);
  assert(ansI[0] == 0);
  assert(ansI[k] == n);
  ll ans2 = 0;
  for (int i = 0; i < k; ++i) {
    assert(ansI[i] < ansI[i + 1]);
    ans2 += c[ansI[i]][ansI[i + 1]];
  }
  assert(ans2 == ans);
}