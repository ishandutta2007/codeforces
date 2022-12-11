#include <bits/stdc++.h>
using namespace std;

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  v.reserve(n * n * 2);
  map<int, int> mp;
  for (int &x : v) {
    cin >> x;
    mp[x]++;
  }
  for (auto &[k, v] : mp) {
    if (v % 2) {
      cout << "-1\n";
      return;
    }
  }

  vector<pair<int, int>> moves;
  vector<int> lens;

  size_t i = 0;
  int offset = 0;
  while (i < v.size()) {
    if (v[i] == v[i + 1]) {
      lens.push_back(2);
      i += 2;
      continue;
    }
    size_t j = i + 1;
    while (v[j] != v[i]) j++;

    for (size_t k = 0; k < j - i - 1; k++) {
      moves.emplace_back(offset + j + k + 1, v[i + k + 1]);
    }

    offset += static_cast<int>(j - i - 1) * 2;
    lens.emplace_back((j - i) * 2);

    vector<int> tmp;
    for (size_t k = i + 1; k < j; k++) tmp.push_back(v[k]);
    i += 2;
    auto ptr = i;
    while (!tmp.empty()) {
      v[ptr++] = tmp.back();
      tmp.pop_back();
    }
  }

  cout << moves.size() << "\n";
  for (auto &[a, b] : moves) cout << a << " " << b << "\n";
  cout << lens.size() << "\n";
  for (auto &len : lens) cout << len << " ";
  cout << "\n";
  if (D) cout << "\n";
}

int main() {
  if (D) freopen("../a.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = (D ? 3 : 1);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}