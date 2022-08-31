#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

bool cmax(int &x, int y) {
  return x < y ? x = y, true : false;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  int m = a[n - 1];
  vector<int> prime, minp(m + 1);
  for (int i = 2; i <= m; ++i) {
    if (!minp[i]) {
      prime.push_back(i);
      minp[i] = i;
    }
    for (auto p : prime) {
      if (i * p > m) {
        break;
      }
      minp[i * p] = p;
      if (i % p == 0) {
        break;
      }
    }
  }
  vector<int> appear(m + 1);
  for (auto x : a) {
    ++appear[x];
  }
  bool add = false;
  vector<int> cover(m + 1), times(m + 1);
  for (int i = 1; i <= m; ++i) {
    if (appear[i] == 3) {
      add = true;
    }
  }

  vector<int> all;

  auto insert = [&](int x) {
    bool useful = false;
    int old = x;
    while (x != 1) {
      int p = minp[x], e = 0;
      while (x % p == 0) {
        x /= p;
        ++e;
      }
      if (cmax(cover[p], e)) {
        useful = true;
        times[p] = 1;
      } else if (cover[p] == e) {
        ++times[p];
      }
    }
    if (useful) {
      all.push_back(old);
    } else {
      x = old;
      while (x != 1) {
        int p = minp[x], e = 0;
        while (x % p == 0) {
          x /= p;
          ++e;
        }
        if (cover[p] == e) {
          --times[p];
        }
      }
    }
    return useful;
  };

  for (int i = m; i; --i) {
    if (appear[i] >= 2) {
      if (!insert(i)) {
        add = true;
      }
      if (!insert(i - 1)) {
        add = true;
      }
    }
  }
  for (int i = m; i; --i) {
    if (appear[i] == 1) {
      if (!insert(i)) {
        if (!insert(i - 1)) {
          add = true;
        }
      }
    }
  }

  auto check = [&](int x) {
    bool useful = false;
    while (x != 1) {
      int p = minp[x], e = 0;
      while (x % p == 0) {
        x /= p;
        ++e;
      }
      if (cover[p] == e && times[p] == 1) {
        useful = true;
        break;
      }
    }
    return !useful;
  };

  for (auto x : all) {
    if (check(x)) {
      add = true;
      break;
    }
  }
  int answer = 1;
  for (int i = 2; i <= m; ++i) {
    answer = mul(answer, power(i, cover[i]));
  }
  if (add) {
    answer = (answer + 1) % md;
  }
  printf("%d\n", answer);
  return 0;
}