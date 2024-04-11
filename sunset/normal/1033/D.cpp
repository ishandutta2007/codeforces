#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

long long square_root(long long x) {
  long long result = pow(x, 1.0 / 2);
  while (result * result < x) {
    ++result;
  }
  while (result * result > x) {
    --result;
  }
  return result * result == x ? result : -1;
}

long long cube_root(long long x) {
  long long result = pow(x, 1.0 / 3);
  while (result * result * result < x) {
    ++result;
  }
  while (result * result * result > x) {
    --result;
  }
  return result * result * result == x ? result : -1;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  map<long long, int> power;
  vector<long long> a;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x;
    y = cube_root(x);
    if (~y) {
      power[y] += 3;
      continue;
    }
    y = square_root(x);
    if (~y) {
      long long z = square_root(y);
      if (~z) {
        power[z] += 4;
      } else {
        power[y] += 2;
      }
      continue;
    }
    a.push_back(x);
  }
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] != a[j]) {
        long long x = __gcd(a[i], a[j]);
        if (x != 1) {
          power[x];
        }
      }
    }
  }
  map<long long, int> free;
  for (int i = 0; i < a.size(); ++i) {
    bool found = false;
    for (auto p : power) {
      long long x = p.first;
      if (a[i] % x == 0) {
        ++power[x];
        ++power[a[i] / x];
        found = true;
        break;
      }
    }
    if (!found) {
      ++free[a[i]];
    }
  }
  int answer = 1;
  for (auto p : power) {
    answer = (long long)answer * (p.second + 1) % md;
  }
  for (auto p : free) {
    answer = (long long)answer * (p.second + 1) % md * (p.second + 1) % md;
  }
  printf("%d\n", answer);
  return 0;
}