#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

struct num {
  vector<long long> z;

  num() {
    z = vector<long long>(5);
  }

  num operator + (const num &b) const {
    num c;
    for (int i = 0; i < 5; ++i) {
      c.z[i] = z[i] + b.z[i];
    }
    return c;
  }
  
  num operator - (const num &b) const {
    num c;
    for (int i = 0; i < 5; ++i) {
      c.z[i] = z[i] - b.z[i];
    }
    return c;
  }

  num operator * (const num &b) const {
    num c;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        c.z[(i + j) % 5] += z[i] * b.z[j];
      }
    }
    return c;
  }

  num shift(int w) {
    num res;
    for (int i = 0; i < 5; ++i) {
      res.z[(i + w) % 5] = z[i];
    }
    return res;
  }
};

long long power(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x *= x) {
    if (y & 1) {
      res *= x;
    }
  }
  return res;
}

num power(num x, int y) {
  num res;
  res.z[0] = 1;
  for (; y; y >>= 1, x = x * x) {
    if (y & 1) {
      res = res * x;
    }
  }
  return res;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<num> a(N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x].z[0];
  }
  function<void(int, int, bool)> dft = [&](int s, int n, bool idft) {
    if (n != 1) {
      for (int i = 0; i < n; i += n / 10) {
        dft(s + i, n / 10, idft);
      }
      for (int i = 0; i < n / 10; ++i) {
        vector<num> temp(10);
        for (int j = 0; j < 10; ++j) {
          for (int k = 0; k < 10; ++k) {
            int w = j * k % 10;
            if (idft) {
              w = (10 - w) % 10;
            }
            if (w & 1) {
              temp[j] = temp[j] - a[s + k * (n / 10) + i].shift(w + 5 >> 1);
            } else {
              temp[j] = temp[j] + a[s + k * (n / 10) + i].shift(w >> 1);
            }
          }
        }
        for (int j = 0; j < 10; ++j) {
          a[s + j * (n / 10) + i] = temp[j];
        }
      }
    }
  };
  dft(0, N, false);
  for (int i = 0; i < N; ++i) {
    a[i] = power(a[i], n);
  }
  dft(0, N, true);
  long long inv = power(3125, LLONG_MAX);
  for (int i = 0; i < n; ++i) {
    cout << ((a[i].z[0] - a[i].z[1] >> 5) * inv & (1ll << 58) - 1) << "\n";
  }
  return 0;
}