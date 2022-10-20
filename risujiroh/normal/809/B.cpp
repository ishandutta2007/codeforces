#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

bool query(int i, int j = -1) {
  if (j == -1) {
    j = i + 1;
  }
  cout << "1 " << j + 1 << ' ' << i + 1 << endl;
  string s;
  cin >> s;
  return s == "NIE";
}

void answer(int x, int y) {
  cout << "2 " << x + 1 << ' ' << y + 1 << endl;
  exit(0);
}

int main() {
  int n, k;
  cin >> n >> k;
  bool l01 = query(0, 1);
  bool l10 = query(1, 0);
  if (not l01 and not l10) {
    answer(0, 1);
  }
  bool r10 = query(n - 1, n - 2);
  bool r01 = query(n - 2, n - 1);
  if (not r10 and not r01) {
    answer(n - 2, n - 1);
  }
  if (l01 and r10) {
    answer(0, n - 1);
  }
  auto bin = [&](int ng, int ok) {
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (query(mid, mid + 1) ? ok : ng) = mid;
    }
    return ok;
  };
  auto bin01 = [&](int l, int r) {
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (query(mid, mid + 1)) {
        r = mid;
      } else {
        return bin(mid, r);
      }
    }
    return -1;
  };
  auto bin10 = [&](int l, int r) {
    while (r - l > 1) {
      int mid = (l + r + 1) / 2;
      if (query(mid + 1, mid)) {
        l = mid;
      } else {
        return bin(l, mid);
      }
    }
    return -1;
  };
  if (l01) {
    answer(0, bin01(0, n - 2));
  } else if (r10) {
    answer(bin10(0, n - 2), n - 1);
  } else {
    int x = bin(0, n - 2);
    if (not query(x, x + 1)) {
      answer(x, x + 1);
    }
    if (not query(x, x - 1)) {
      answer(x - 1, x);
    }
    int y = bin01(x, n - 2);
    if (y == -1) {
      y = bin10(0, x - 1);
    }
    answer(x, y);
  }
}