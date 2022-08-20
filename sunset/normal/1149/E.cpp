#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    ++deg[to];
  }
  vector<int> order;
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      order.push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    int x = order[i];
    for (auto y : adj[x]) {
      if (!--deg[y]) {
        order.push_back(y);
      }
    }
  }
  vector<int> last(n + 1, -1);
  vector<int> nim(n);
  vector<int> sg(n);
  for (int i = n - 1; ~i; --i) {
    int x = order[i];
    for (auto y : adj[x]) {
      last[sg[y]] = x;
    }
    while (last[sg[x]] == x) {
      ++sg[x];
    }
    nim[sg[x]] ^= a[x];
  }
  int high = -1;
  for (int i = 0; i < n; ++i) {
    if (nim[i]) {
      high = i;
    }
  }
  if (high == -1) {
    cout << "LOSE" << "\n";
  } else {
    cout << "WIN" << "\n";
    for (int i = 0; i < n; ++i) {
      if (sg[i] == high && a[i] >= (a[i] ^ nim[sg[i]])) {
        a[i] ^= nim[sg[i]];
        nim[sg[i]] = 0;
        for (auto j : adj[i]) {
          a[j] ^= nim[sg[j]];
          nim[sg[j]] = 0;
        }
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << "\n";
  }
  return 0;
}