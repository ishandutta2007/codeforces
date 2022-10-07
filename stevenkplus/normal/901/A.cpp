// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

// =========== Solution ============= //

int main() {
  int h;
  cin >> h;
  vector<int> v(h + 1);

  vector<int> a, b;
  bool ans = false;
  int id = 0;
  for (int i = 0; i < h + 1; ++i) {
    cin >> v[i];
    if (i > 0 && v[i] > 1 && v[i - 1] > 1) {
      ans = true;
      for (int j = 0; j < v[i]; ++j) {
        a.push_back(id);
        b.push_back(j == 0 ? id : id - 1);
      }
    } else {
      for (int j = 0; j < v[i]; ++j) {
        a.push_back(id);
        b.push_back(id);
      }
    }
    id += v[i];
  }

  if (!ans) {
    cout << "perfect\n";
    return 0;
  }

  cout << "ambiguous\n";
  for (int i: a) {
    cout << i << " ";
  }
  cout << "\n";
  for (int i: b) {
    cout << i << " ";
  }
  cout << "\n";

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases