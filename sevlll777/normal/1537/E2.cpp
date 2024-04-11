#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244853;
const int M2 = 996179179;
const int p = 71;
const int N = 500009;
string s;
int n, k;
int pw1[N], pw2[N];
int P1[N], P2[N];

int sub(int l, int r) {
  int hb = P1[r], hs = P1[l - 1];
  hb += (M - (hs * pw1[r - l + 1] % M)) % M;
  hb %= M;
  int hb2 = P2[r], hs2 = P2[l - 1];
  hb2 += (M2 - (hs2 * pw2[r - l + 1] % M2)) % M2;
  hb2 %= M2;
  return hb * (int) 1e9 + hb2;
}

int cmp(int l1, int r1, int l2, int r2) {
  int len = 1 + min(r1 - l1, r2 - l2);
  int l = -1, r = len;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int rr1 = l1 + m, rr2 = l2 + m;
    if (sub(l1, rr1) == sub(l2, rr2)) {
      l = m;
    } else {
      r = m;
    }
  }
  if (r == len) {
    return 0;
  }
  if (s[l1 + l + 1] < s[l2 + l + 1]) {
    return -1;
  }
  return 1;
}

int roflan(vector<int> x) {
  if (x.size() == 1) {
    return x[0];
  }
  if (x.size() == 2) {
    int l = x[0];
    int s = x[0] + 1;
    while (s + l - 1 <= x[1]) {
      int verd = cmp(1, x[0], s, s + l - 1);
      if (verd == -1) {
        return x[0];
      } else if (verd == 1) {
        return x[1];
      }
      s += l;
    }
    int verd = cmp(1, x[1] - s + 1, s, x[1]);
    if (verd == -1) {
      return x[0];
    } else if (verd == 1) {
      return x[1];
    } else {
      verd = cmp(x[1] - s + 2, x[0], 1, x[0] - (x[1] - s + 2) + 1);
      if (verd == -1) {
        return x[0];
      } else if (verd == 1) {
        return x[1];
      } else {
        return x[0];
      }
    }
  }
  vector<int> a, b;
  for (int i = 0; i < (int) x.size(); i++) {
    if (i < (int) x.size() / 2) {
      a.pb(x[i]);
    } else {
      b.pb(x[i]);
    }
  }
  return roflan({roflan(a), roflan(b)});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  pw1[0] = 1;
  pw2[0] = 1;
  for (int i = 1; i < N; i++) {
    pw1[i] = (p * pw1[i - 1]) % M;
    pw2[i] = (p * pw2[i - 1]) % M2;
  }
  cin >> n >> k >> s;
  if (k < n) {
    n = k;
    while (s.size() > k) s.pop_back();
  }
  s = '-' + s;
  for (int i = 1; i <= n; i++) {
    P1[i] = (P1[i - 1] * p + (s[i] - 'a' + 107)) % M;
    P2[i] = (P2[i - 1] * p + (s[i] - 'a' + 107)) % M2;
  }
  vector<int> x;
  for (int y = 1; y <= n; y++) {
    x.pb(y);
  }
  int kek = roflan(x);
  for (int i = 0; i < k; i++) {
    cout << s[1 + i % kek];
  }
}