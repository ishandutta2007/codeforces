#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *max_element(a.begin(), a.end());
  vector<int> primes, minp(m + 1);
  for (int i = 2; i <= m; ++i) {
    if (!minp[i]) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > m) {
        break;
      }
      minp[i * p] = p;
      if (i % p == 0) {
        break;
      }
    }
  }

  auto factorization = [&](int x) {
    vector<pair<int, int>> result;
    vector<int> primes;
    while (x != 1) {
      int counter = 0, p = minp[x];
      while (x % p == 0) {
        x /= p;
        ++counter;
      }
      if (counter & 1) {
        primes.push_back(p);
      }
    }
    function<void(int, int, int)> dfs = [&](int x, int product, int dist) {
      if (x == primes.size()) {
        result.emplace_back(product, dist);
      } else {
        dfs(x + 1, product * primes[x], dist);
        dfs(x + 1, product, dist + 1);
      }
    };
    dfs(0, 1, 0);
    return result;
  };

  vector<vector<int>> answer(n, vector<int> (15));
  vector<vector<int>> right(m + 1, vector<int> (8, n));
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j < 15; ++j) {
      answer[i][j] = n;
    }
    vector<pair<int, int>> all = factorization(a[i]);
    for (auto p : all) {
      for (int j = 0; j < 8; ++j) {
        answer[i][j + p.second] = min(answer[i][j + p.second], right[p.first][j]);
      }
    }
    for (auto p : all) {
      right[p.first][p.second] = i;
    }
    for (int j = 1; j < 15; ++j) {
      answer[i][j] = min(answer[i][j], answer[i][j - 1]);
    }
  }
  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    --l[i];
    --r[i];
  }
  vector<int> result(q, 15);
  for (int i = 14; ~i; --i) {
    vector<int> to(n);
    for (int j = 0; j < n; ++j) {
      to[j] = answer[j][i];
    }
    for (int j = n - 1; j; --j) {
      to[j - 1] = min(to[j - 1], to[j]);
    }
    for (int j = 0; j < q; ++j) {
      if (to[l[j]] <= r[j]) {
        result[j] = i;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
  return 0;
}