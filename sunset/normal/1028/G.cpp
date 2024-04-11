#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll limit = 10000;

int main() {
  vector<ll> w(5);
  w[0] = limit;
  for (int i = 1; i < 5; ++i) {
    w[i] = limit + (limit + 1) * w[i - 1];
  }
  vector<map<int, vector<ll>>> mem(5);
  
  function<ll(ll, int)> dp = [&](ll left, int depth) {
    if (left >= limit) {
      return left + w[depth] - 1;
    }
    if (!depth) {
      return (left << 1) - 1;
    }
    int ask = left;
    vector<ll> &v = mem[depth][left];
    while (true) {
      left = dp(left, depth - 1);
      if (!ask) {
        break;
      }
      --ask;
      v.push_back(++left);
      ++left;
    }
    return left;
  };

  function<void(ll, int)> go = [&](ll left, int depth) {
    if (left >= limit) {
      while (depth--) {
        vector<ll> v;
        for (ll i = left + w[depth]; v.size() < limit; i += w[depth] + 1) {
          v.push_back(i);
        }
        printf("%d", v.size());
        for (auto x : v) {
          printf(" %lld", x);
        }
        putchar(10);
        fflush(stdout);
        int result;
        scanf("%d", &result);
        if (~result) {
          if (result) {
            left = v[result - 1] + 1;
          }
        } else {
          exit(0);
        }
      }
      printf("%d", limit);
      for (int i = 0; i < limit; ++i) {
        printf(" %lld", left + i);
      }
      putchar(10);
      fflush(stdout);
      exit(0);
    }
    if (!depth) {
      printf("%lld", left);
      for (int i = 0; i < left; ++i) {
        printf(" %lld", left + i);
      }
      putchar(10);
      fflush(stdout);
      exit(0);
    }
    printf("%lld", left);
    for (auto x : mem[depth][left]) {
      printf(" %lld", x);
    }
    putchar(10);
    fflush(stdout);
    int result;
    scanf("%d", &result);
    if (~result) {
      go(result ? mem[depth][left][result - 1] + 1 : left, depth - 1);
    } else {
      exit(0);
    }
  };
  
  dp(1, 4);
  go(1, 4);
  return 0;
}