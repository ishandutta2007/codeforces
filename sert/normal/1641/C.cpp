#include <bits/stdc++.h>
using namespace std;

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

void mne(int &a, int b) { if (b < a) a = b; }
void mxe(int &a, int b) { if (b > a) a = b; }

int getL(const set<pair<int, int>>::iterator &it) {
  return it->second;
}

int getR(const set<pair<int, int>>::iterator &it) {
  return it->first;
}

struct ST {
  static constexpr int INF = static_cast<int>(1e9) + 7;
  vector<int> v;
  int sz;
  explicit ST(int sz = 0): sz(sz) {
    v.assign(sz * 4, INF);
  }

  void add(int pos, int val, int i = 0, int l = 0, int r = -1) {
    //if (r == -1) cout << "add " << pos << " " << val << "\n";
    if (r == -1) r = sz;
    if (l + 1 == r) {
      v[i] = min(v[i], val);
      return;
    }
    int m = (l + r) / 2;
    if (pos < m) add(pos, val, i * 2 + 1, l, m);
    else add(pos, val, i * 2 + 2, m, r);
    v[i] = min(v[i * 2 + 1], v[i * 2 + 2]);
  }

  int get(int L, int R, int i = 0, int l = 0, int r = -1) const {
    if (r == -1) r = sz;
    if (L >= r || l >= R) return INF;
    if (L <= l && r <= R) { return v[i]; }
    int m = (l + r) / 2;
    int ans = min(get(L, R, i * 2 + 1, l, m), get(L, R, i * 2 + 2, m, r));
    //cout << "min " << L << " " << R << " = " << ans << "\n";
    return ans;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  set<pair<int, int>> z;
  z.insert(make_pair(-100, -101));
  z.insert(make_pair(n + 100, n + 99));

  ST st(n + 2);

  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      if (x == 1) {
        st.add(l, r);
      } else {
        auto it = z.lower_bound(make_pair(r + 1, -300));
        int ln = l;
        int rn = r;
        vector<pair<int, int>> del;
        if (r + 1 >= getL(it)) {
          rn = getR(it);
        } else {
          it--;
        }

        while (getR(it) + 1 >= l) {
          ln = min(l, getL(it));
          del.push_back(*it);
          it--;
        }

        for (auto &d : del) {
          z.erase(d);
        }
        z.insert(make_pair(rn, ln));
      }
    } else {
      int x;
      cin >> x;
      auto it = z.lower_bound(make_pair(x, -300));
      if (getL(it) <= x) {
        cout << "NO\n";
        continue;
      }
      int oldL = getL(it);
      int oldR = getR(it);
      it--;
      int ll = (getR(it) + 1 == x ? getL(it) : x);
      int rr = (x + 1 == oldL ? oldR : x);
      if (st.get(ll, x + 1) <= rr) {
        cout << "YES\n";
        continue;
      }
      cout << "N/A\n";
    }
  }
}

int main() {
  if (D) freopen("../a.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
//  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}