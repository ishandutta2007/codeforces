#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = (int) (1e9 + 7);
const int D = (int) (1e6 + 107);

int bin(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1)
      res = (ll) res * x % mod;
    x = (ll) x * x % mod;
    y >>= 1;
  }
  return res;
}

void add(int& x, int y) {
  if ((x += y) >= mod)
    x -= mod;
}

void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += mod;
}

int a[D], b[D];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (auto& x : k)
      cin >> x;
    if (p == 1)
      cout << (n & 1) << '\n';
    else {
      sort(k.rbegin(), k.rend());
      vector<int> toclear;
      set<int> diff;
      auto inc_a = [&] (int i) {
        diff.erase(i);
        ++a[i];
        if (a[i] != b[i])
          diff.insert(i);
        toclear.push_back(i);
        while (a[i] == p) {
          diff.erase(i);
          a[i] = 0;
          if (a[i] != b[i])
            diff.insert(i);
          ++i;
          diff.erase(i);
          ++a[i];
          if (a[i] != b[i])
            diff.insert(i);
          toclear.push_back(i);
        }
      };
      auto inc_b = [&] (int i) {
        diff.erase(i);
        ++b[i];
        if (a[i] != b[i])
          diff.insert(i);
        toclear.push_back(i);
        while (b[i] == p) {
          diff.erase(i);
          b[i] = 0;
          if (a[i] != b[i])
            diff.insert(i);
          ++i;
          diff.erase(i);
          ++b[i];
          if (a[i] != b[i])
            diff.insert(i);
          toclear.push_back(i);
        }
      };
      for (auto x : k) {
        if (diff.empty() || a[*diff.rbegin()] < b[*diff.rbegin()])
          inc_a(x);
        else
          inc_b(x);
      }
      if (diff.empty())
        cout << "0\n";
      else {
        int ans = 0;
        if (a[*diff.rbegin()] < b[*diff.rbegin()]) {
          for (auto x : diff) {
            sub(ans, (ll) a[x] * bin(p, x) % mod);
            add(ans, (ll) b[x] * bin(p, x) % mod);
          }
        } else {
          for (auto x : diff) {
            add(ans, (ll) a[x] * bin(p, x) % mod);
            sub(ans, (ll) b[x] * bin(p, x) % mod);
          }
        }
        cout << ans << '\n';
      }
      for (auto x : toclear) {
        a[x] = 0;
        b[x] = 0;
      }
    }
  }
  return 0;
}