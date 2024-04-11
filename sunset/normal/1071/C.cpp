#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n < 8) {
    vector<int> prev(1 << n, -1);
    queue<int> q;
    int x = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i]) {
        x |= 1 << i;
      }
    }
    q.push(x);
    prev[x] = 1 << n;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int d = 1; d < n; ++d) {
        for (int i = 0; i + (d << 1) < n; ++i) {
          int y = x ^ (1 << i) ^ (1 << i + d) ^ (1 << i + (d << 1));
          if (!~prev[y]) {
            prev[y] = x;
            q.push(y);
          }
        }
      }
    }
    if (!~prev[0]) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<vector<int>> answer;
      for (int x = 0; prev[x] < 1 << n; x = prev[x]) {
        int y = x ^ prev[x];
        answer.push_back(vector<int> ());
        for (int i = 0; i < n; ++i) {
          if (y >> i & 1) {
            answer.back().push_back(i);
          }
        }
      }
      cout << answer.size() << endl;
      reverse(answer.begin(), answer.end());
      for (auto p : answer) {
        cout << p[0] + 1 << " " << p[1] + 1 << " " << p[2] + 1 << endl;
      }
    }
    return 0;
  }
  cout << "YES" << endl;
  vector<vector<int>> answer;
  set<int> one;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      one.insert(i);
    }
  }
  
  auto edit = [&](int x) {
    if (a[x]) {
      one.erase(x);
    } else {
      one.insert(x);
    }
    a[x] = !a[x];
  };

  auto flip = [&](int x, int y, int z) {
    answer.push_back({x, y, z});
    edit(x);
    edit(y);
    edit(z);
  };
  
  while (!one.empty() && *one.rbegin() >= 15) {
    int x = *one.rbegin();
    if (!a[x - 1] && !a[x - 2]) {
      flip(x - 6, x - 3, x);
    } else if (!a[x - 1]) {
      flip(x - 4, x - 2, x);
    } else if (!a[x - 2]) {
      int one = 0;
      for (int i = x - 5; i < x - 2; ++i) {
        if (a[i]) {
          ++one;
        }
      }
      if (!one) {
        flip(x - 2, x - 1, x);
        flip(x - 10, x - 6, x - 2);
      } else if (one == 1) {
        int p = 0;
        for (int i = x - 5; i < x - 2; ++i) {
          if (a[i]) {
            p = x - i;
          }
        }
        flip(x - p * 2, x - p, x);
        flip(x - 11, x - 6, x - 1);
      } else if (one == 2) {
        int p = 0, q = 0;
        for (int i = x - 5; i < x - 2; ++i) {
          if (a[i]) {
            if (!p) {
              p = x - i;
            } else {
              q = x - i;
            }
          }
        }
        flip(x - q * 2, x - q, x);
        flip(x - p * 2 + 1, x - p, x - 1);
      } else {
        flip(x - 5, x - 3, x - 1);
        flip(x - 8, x - 4, x);
      }
    } else {
      flip(x - 2, x - 1, x);
    }
  }
  n = min(n, 15);
  vector<int> prev(1 << n, -1);
  queue<int> q;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      x |= 1 << i;
    }
  }
  q.push(0);
  prev[0] = 1 << n;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int d = 1; d < n; ++d) {
      for (int i = 0; i + (d << 1) < n; ++i) {
        int y = x ^ (1 << i) ^ (1 << i + d) ^ (1 << i + (d << 1));
        if (!~prev[y]) {
          prev[y] = x;
          q.push(y);
        }
      }
    }
  }
  for (; prev[x] < 1 << n; x = prev[x]) {
    int y = x ^ prev[x];
    answer.push_back(vector<int> ());
    for (int i = 0; i < n; ++i) {
      if (y >> i & 1) {
        answer.back().push_back(i);
      }
    }
  }
  cout << answer.size() << endl;
  for (auto p : answer) {
    cout << p[0] + 1 << " " << p[1] + 1 << " " << p[2] + 1 << endl;
  }
  return 0;
}