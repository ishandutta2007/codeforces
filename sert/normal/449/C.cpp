#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 41;

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int getmaxPrime(int x) {
  for (int i = 2; true; i++) if (x % i == 0) return i;
}

void solve() {  
  int n;
  cin >> n;
  vector<int> maxPrime(n + 1, -1);
  vector<vector<int>> values(n + 1);
  for (int i = 2; i <= n; i++) {
    if (maxPrime[i] != -1) continue;    
    for (int j = i; j <= n; j += i) {
        maxPrime[j] = i;
    }
  }
  for (int i = 2; i <= n; i++) values[maxPrime[i]].push_back(i);
  vector<pair<int, int>> ans;
  for (int i = 3; i <= n; i++) {
    if ((int)values[i].size() < 2) continue;
    swap(values[i][1], values[i].back());
    for (int j = 0; j + 1 < (int)values[i].size(); j += 2) {
      ans.emplace_back(values[i][j], values[i][j + 1]);
    }
    if (values[i].size() % 2 == 1) {
      values[2].push_back(values[i].back());
    }
  }
  for (int i = 0; i + 1 < (int)values[2].size(); i += 2) {
    ans.emplace_back(values[2][i], values[2][i + 1]);
  }
  cout << ans.size() << "\n";
  for (auto &[a, b] : ans) {
    cout << a << " " << b << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SERT
  for (int i = 0; i < 4; i++) solve();
#else
  solve();
#endif
}