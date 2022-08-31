#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string low, high;
  cin >> low >> high;
  for (int i = high.length() - 1; ~i; --i) {
    if (high[i] == '0') {
      high[i] = '1';
      break;
    } else {
      high[i] = '0';
      if (!i) {
        high = "1" + high;
      }
    }
  }
  int zz, zo, oz, oo;
  cin >> zz >> zo >> oz >> oo;
  if (oz - zo < 0 || oz - zo > 1) {
    puts("0");
    return 0;
  }
  
  int one = oz + (oz == zo), zero = zo + (oz > zo), ones = one + oo, zeros = zero + zz, n = ones + zeros;
  vector<int> fac(n + 1), ifac(n + 1);
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = mul(md - md / i, ifac[md % i]);
  }
  for (int i = 2; i <= n; ++i) {
    ifac[i] = mul(ifac[i], ifac[i - 1]);
  }

  auto binom = [&](int x, int y) {
    if (x < 0 || y < 0 || x < y) {
      return 0;
    } else {
      return mul(fac[x], mul(ifac[y], ifac[x - y]));
    }
  };

  auto solve = [&](string limit) {
    if (limit.length() < n) {
      return 0;
    } else if (limit.length() > n) {
      return mul(binom(ones - 1, one - 1), !zeros && !zero ? 1 : binom(zeros - 1, zero - 1));
    } else {
      int o = 0, z = 0, os = 0, zs = 0, last = 0, answer = 0;
      for (int i = 0; i < limit.size(); ++i) {
        if (i && limit[i] == '1') {
          ++zs;
          if (last) {
            ++z;
          }
          answer = add(answer, mul(ones == os && one == o ? 1 : binom(ones - os - 1, one - o - 1), binom(zeros - zs, zero - z)));
          --zs;
          if (last) {
            --z;
          }
        }
        if (limit[i] == '1') {
          ++os;
          if (!last) {
            last = 1;
            ++o;
          }
        } else {
          ++zs;
          if (last) {
            last = 0;
            ++z;
          }
        }
      }
      return answer;
    }
  };

  printf("%d\n", sub(solve(high), solve(low)));
  return 0;
}