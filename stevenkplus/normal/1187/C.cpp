// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// CURRENT STREAK (fun level): 3 AC in a row
// CURRENT STREAK (easy level): 1 AC in a row

int find(vector<int> &dsu, int x) {
  if (dsu[x] == x) return x;
  return dsu[x] = find(dsu, dsu[x]);
}

void merge(vector<int> &dsu, int a, int b) {
  a = find(dsu, a);
  b = find(dsu, b);
  if (a != b) {
    dsu[a] = b;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> dsu(n); // v[i] is number of Ls - Rs of (type 1)
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
  }
  vector<pii> b;
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    --r;
    if (t == 1) {
      for (int j = l; j < r; ++j) {
        merge(dsu, j, j + 1);
      }
    } else {
      b.push_back(pii(l, r));
    }
  }

  vector<int> ans(n);
  int val = 1e9;
  for(int i = 0; i < n; ++i) {
    ans[i] = val;
    if (i + 1 < n && find(dsu, i) != find(dsu, i + 1)) {
      --val;
    }
  }

  bool ansb = true;
  for (auto p: b) {
    if (ans[p.fi] <= ans[p.se]) ansb = false;
  }

  if (ansb) {
    cout << "YES\n";
    for (auto i: ans) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }

  // [1, 4] [3, 6] are sorted
  // [2, 5] not sorted
}