#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1001000;
const int MOD1 = 998244353;
const int MOD2 = 1E9 + 7;
const int BASE1 = 137;
const int BASE2 = 139;
typedef struct {
  ll h1;
  ll h2;
  int len;
  int offset;
} hsh;

ll pows1[MAXN], pows2[MAXN];

bool eq(hsh a, hsh b) {
  if (a.offset > b.offset) {
    swap(a, b);
  }
  a.h1 *= pows1[b.offset - a.offset];
  a.h1 %= MOD1;
  a.h2 *= pows2[b.offset - a.offset];
  a.h2 %= MOD2;
  return a.h1 == b.h1 && a.h2 == b.h2;
}

hsh pref[MAXN], suff[MAXN];

hsh add(hsh a, char c) {
  return {(a.h1 + c * pows1[a.len + a.offset]) % MOD1, (a.h2 + c * pows2[a.len + a.offset]) % MOD2, a.len + 1, a.offset};
}

hsh sub(hsh a, hsh b) {
  return {(MOD1 + a.h1 - b.h1) % MOD1, (MOD2 + a.h2 - b.h2) % MOD2, a.len - b.len, b.len};
}

int n;
bool ispal(int a, int b) {
  if (a < 0 || b > n) return false;
  hsh forward = sub(pref[b], pref[a]);
  hsh backward = sub(suff[a], suff[b]);
  return eq(forward, backward);
}

void p(hsh h) {
  printf("{%d, %d, %d, %d}\n", int(h.h1), int(h.h2), h.len, h.offset);
}

int main() {
  pows1[0] = pows2[0] = 1;
  for(int i = 0; i + 1 < MAXN; ++i) {
    pows1[i + 1] = (pows1[i] * BASE1) % MOD1;
    pows2[i + 1] = (pows2[i] * BASE2) % MOD2;
  }

  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    string s;
    cin >> s;
    n = s.size();
    int ans = 0;
    string ansS = "";
    for (int rep = 0; rep < 2; ++rep) {
      int ansI = -1, ansJ = -1;
      pref[0] = hsh();
      for(int i = 0; i < n; ++i) {
        pref[i + 1] = add(pref[i], s[i]);
      }
      suff[n] = hsh();
      for(int i = n - 1; i >= 0; --i) {
        suff[i] = add(suff[i + 1], s[i]);
      }

      vector<int> v[] = {vector<int>(n + 1), vector<int>(n + 1)};
      for (int i = 0; i < n; ++i) {
        for (int j = i; j <= i + 1; ++j) {
          if (i + j > n) continue;
          int lo = 0;
          int hi = n;
          while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (ispal(i - mid, j + mid)) lo = mid;
            else hi = mid;
          }
          v[j - i][i - lo] = 2 * lo + j - i;
        }
      }
      for(int i = 0; i + 1 < n; ++i) {
        for(int j = 0; j < 2; ++j) {
          v[j][i + 1] = max(v[j][i + 1], v[j][i] - 2);
        }
      }
      for(int i = 0; i + i <= n; ++i) {
        if (eq(pref[i], suff[n - i])) {
          for(int j = 0; j < 2; ++j) {
            int l = 2 * i + v[j][i];
            if (l > n) l -= 2 * (l - (n - 1)) / 2;
            if (l > ans) {
              ans = l;
              ansI = i;
              ansJ = j;
            }
          }
        } else {
        }
      }

      if (ansI != -1) {
        ansS = s.substr(0, ansI) + s.substr(ansI, ans - 2 * ansI) + s.substr(n - ansI);
      }
      reverse(s.begin(), s.end());
    }
    cout << ansS << "\n";
  }
}