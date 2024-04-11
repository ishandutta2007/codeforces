#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> imos(n + 1);
    while (m--) {
      int r;
      cin >> r;
      ++imos[0];
      --imos[r];
    }
    ++imos[0];
    --imos[n];
    for (int i = 0; i < n; ++i) {
      imos[i + 1] += imos[i];
    }
    vector<long long> res(26);
    for (int i = 0; i < n; ++i) {
      res[s[i] - 'a'] += imos[i];
    }
    for (int i = 0; i < 26; ++i) {
      cout << res[i] << " \n"[i == 25];
    }
  }
}