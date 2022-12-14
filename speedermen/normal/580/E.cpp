#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 10;

const int P[2] = {239, 997};
const int Mod[2] = {1e9 + 7, 1e9 + 9};

int n, m, k;
string str;
int t[2][4 * MaxN], value[2][4 * MaxN];
int hp[2][MaxN], hs[2][MaxN];

void build(int i, int l, int r) {
  if (l == r) {
    t[1][i] = t[0][i] = str[l] - '0' + 139;
    value[1][i] = value[0][i] = -1;
    return;
  }
  int m = (l + r) / 2;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  t[0][i] = (t[0][2 * i] + 1LL * t[0][2 * i + 1] * hp[0][m - l + 1]) % Mod[0];
  t[1][i] = (t[1][2 * i] + 1LL * t[1][2 * i + 1] * hp[1][m - l + 1]) % Mod[1];
  value[1][i] = value[0][i] = -1;
}

void push(int v, int l, int r) {
  if (value[0][v] >= 0) {
    if (l != r) {
      value[0][2 * v] = value[0][2 * v + 1] = value[0][v];
      value[1][2 * v] = value[1][2 * v + 1] = value[1][v];
    }
    t[0][v] = 1LL * (value[0][v] + 139) * hs[0][r - l] % Mod[0];
    t[1][v] = 1LL * (value[1][v] + 139) * hs[1][r - l] % Mod[1];
    value[0][v] = value[1][v] = -1;
  }
}

void upd(int i, int l, int r, int L, int R, int v) {
  push(i, l, r);
  if (L > r || R < l) {
    return;
  }
  if (L <= l && r <= R) {
    value[0][i] = v;
    value[1][i] = v;
    push(i, l, r);
    return;
  }
  int m = (l + r) / 2;
  upd(2 * i, l, m, L, R, v);
  upd(2 * i + 1, m + 1, r, L, R, v);
  t[0][i] = (t[0][2 * i] + 1LL * t[0][2 * i + 1] * hp[0][m - l + 1]) % Mod[0];
  t[1][i] = (t[1][2 * i] + 1LL * t[1][2 * i + 1] * hp[1][m - l + 1]) % Mod[1];
}

pair < int, int > get(int i, int l, int r, int L, int R) {
  push(i, l, r);
  if (L <= l && r <= R) {
    return make_pair(t[0][i], t[1][i]);
  }
  int m = (l + r) / 2;
  if (R <= m) {
    push(2 * i + 1, m + 1, r);
    return get(2 * i, l, m, L, R);
  }
  if (L > m) {
    push(2 * i, l, m);
    return get(2 * i + 1, m + 1, r, L, R);
  }
  pair < int, int > Left = get(2 * i, l, m, L, m);
  pair < int, int > Right = get(2 * i + 1, m + 1, r, m + 1, R);
  return make_pair((Left.first + 1LL * hp[0][m - L + 1] * Right.first) % Mod[0],
                  (Left.second + 1LL * hp[1][m - L + 1] * Right.second) % Mod[1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  hp[0][0] = hs[0][0] = 1;
  hp[1][0] = hs[1][0] = 1;
  for (int i = 1; i < MaxN; ++i) {
    hp[0][i] = 1LL * hp[0][i - 1] * P[0] % Mod[0];
    hs[0][i] = (hs[0][i - 1] + hp[0][i]) % Mod[0];
    hp[1][i] = 1LL * hp[1][i - 1] * P[1] % Mod[1];
    hs[1][i] = (hs[1][i - 1] + hp[1][i]) % Mod[1];
  }
  cin >> n >> m >> k;
  cin >> str;
  build(1, 0, str.size() - 1);
  for (int i = 0; i < m + k; ++i) {
    int f, l, r, v;
    cin >> f >> l >> r >> v;
    if (f == 1) {
      upd(1, 0, str.size() - 1, l - 1, r - 1, v);
    } else {
      if (v == r - l + 1 || get(1, 0, str.size() - 1, l - 1, r - v - 1) == get(1, 0, str.size() - 1, l + v - 1, r - 1)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}