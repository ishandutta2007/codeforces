#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5555;
int left[MAXN][MAXN]; // left[i][v] = ways to get ans = v on prefix ending at i
int right[MAXN][MAXN]; // right[i][v] = ways to get ans = v on suffix starting at i

typedef long long ll;

int S[MAXN], F[MAXN], H[MAXN];
int L[MAXN], R[MAXN];
vector<int> pos[MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
    pos[S[i]].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    cin >> F[i] >> H[i];
    vector<int> &p = pos[F[i]];
    if (p.size() >= H[i]) {
      L[i] = p[H[i] - 1];
      R[i] = p[p.size() - H[i]];
    } else {
      L[i] = n + 1;
      R[i] = -1;
    }
    // cout << i << " " << L[i] << " " << R[i] << "\n";
  }

  int ans = 0;
  ll anscnt = 0;
  L[m] = -1;
  F[m] = -1;
  for (int mid = 0; mid <= m; ++mid) {
    if (L[mid] > n) continue;
    // cout << "On " << mid << "\n";
    // mid is right-most cow on left side
    L[mid];
    vector<ll> both(MAXN);
    vector<int> left(MAXN);
    vector<int> right(MAXN);
    for (int i = 0; i < m; ++i) {
      if (mid == i) continue;
      if (L[i] < L[mid] && R[i] > L[mid]) {
        ++both[F[i]];
      } else if (L[i] < L[mid]) {
        ++left[F[i]];
      } else if (R[i] > L[mid]) {
        ++right[F[i]];
      }
    }

    int l = 0;
    int r = 0;
    int b = 0;
    // cout << "COLORS:\n";
    for (int i = 0; i < MAXN; ++i) {
      if (i == F[mid]) {
        both[i] += right[i];
        right[i] = 0;
        left[i] = 1;
      } else {
        int bb = both[i];
        both[i] = left[i] * right[i] % MOD + both[i] * (left[i] + right[i]) % MOD + both[i] * (both[i] - 1) % MOD;
        left[i] += bb;
        right[i] += bb;
      }
      if (both[i]) ++b;
      else if (left[i]) ++l;
      else if (right[i]) ++r;
      if (both[i] || left[i] || right[i]) {
        // cout << i << " " << both[i] << "," << left[i] << "," << right[i] << "\n";
      }
    }
    // cout << "\n";
    int v = 2 * b + l + r;
    if (v < ans) continue;
    if (v > ans) anscnt = 0;
    ans = v;
    // cout << "ans: " << ans << "\n";
    // continue;

    ll cnt = 1;
    for (int i = 0; i < MAXN; ++i) {
      if (both[i]) {
        cnt *= both[i] % MOD;
      } else if (left[i] + right[i]) {
        cnt *= (left[i] + right[i]) % MOD;
      }
      cnt %= MOD;
    }
    // cout << "cnt: " << cnt << "\n";
    anscnt += cnt;
    anscnt %= MOD;
  }
  cout << ans << " " << anscnt << "\n";
}