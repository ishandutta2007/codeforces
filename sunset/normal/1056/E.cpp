#include <bits/stdc++.h>

using namespace std;

const int base = 2333;
const int md0 = 1e9 + 7;
const int md1 = 1e9 + 9;

struct hash_t {
  int hash0, hash1;

  hash_t(int hash0 = 0, int hash1 = 0):hash0(hash0), hash1(hash1) {
  }

  hash_t operator + (const int &x) const {
    return hash_t((hash0 + x) % md0, (hash1 + x) % md1);
  };
  
  hash_t operator * (const int &x) const {
    return hash_t((long long)hash0 * x % md0, (long long)hash1 * x % md1);
  }

  hash_t operator - (const hash_t &x) const {
    return hash_t((hash0 + md0 - x.hash0) % md0, (hash1 + md1 - x.hash1) % md1);
  };

  hash_t operator * (const hash_t &x) const {
    return hash_t((long long)hash0 * x.hash0 % md0, (long long)hash1 * x.hash1 % md1);
  }

  long long get() {
    return (long long)hash0 * md1 + hash1;
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  vector<hash_t> power(m + 1);
  vector<hash_t> hash(m + 1);
  power[0] = hash_t(1, 1);
  for (int i = 0; i < m; ++i) {
    power[i + 1] = power[i] * base;
    hash[i + 1] = hash[i] * base + t[i];
  }
  auto get = [&](int l, int r) {
    return (hash[r] - hash[l] * power[r - l]).get();
  };
  int c0 = 0, c1 = 0;
  for (auto c : s) {
    if (c == '0') {
      ++c0;
    } else {
      ++c1;
    }
  }
  int answer = 0;
  for (int l0 = 1; l0 * c0 < m; ++l0) {
    int l1 = (m - l0 * c0) / c1;
    if (l0 * c0 + l1 * c1 != m) {
      continue;
    }
    bool bad = false;
    bool f0 = false, f1 = false;
    long long h0 = -1, h1 = -1;
    int ptr = 0;
    for (auto c : s) {
      if (c == '0') {
        if (f0) {
          if (get(ptr, ptr + l0) != h0) {
            bad = true;
            break;
          }
        } else {
          f0 = true;
          h0 = get(ptr, ptr + l0);
        }
        ptr += l0;
      } else {
        if (f1) {
          if (get(ptr, ptr + l1) != h1) {
            bad = true;
            break;
          }
        } else {
          f1 = true;
          h1 = get(ptr, ptr + l1);
        }
        ptr += l1;
      }
    }
    if (!bad && (l0 != l1 || h0 != h1)) {
      ++answer;
    }
  }
  cout << answer << endl;
  return 0;
}