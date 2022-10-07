#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1 << 18;
const int A1 = 54637;
const int A2 = 546367;
const int INV1 = 496238816;
const int INV2 = 195917764;
const int MOD1 = 1E9 + 7;
const int MOD2 = 1E9 + 9;
typedef pair<ll, ll> pll;
typedef struct{
  int len;
  int pairs;
  bool leading;
  bool trailing;
  ll hash1;
  ll hash2;
} hsh;

ll pows1[MAXN], pows2[MAXN];
void p(hsh a) {
  // printf("Length=%d, Pairs = %d, hashes = %d, %d, Leading=%d, Trailing=%d\n", a.len, a.pairs, a.hash1, a.hash2, a.leading, a.trailing);
}

hsh seg[2 * MAXN];
hsh zero;

hsh add(hsh a, hsh b) {
  int carry = 0;
  if (a.len > 0 && a.trailing && b.len > 0 && b.leading) {
    a.len -= 1;
    b.len -= 1;
    a.trailing = false;
    b.leading = false;
    a.hash1 = (a.hash1 + MOD1 - pows1[a.len]) % MOD1;
    b.hash1 = (b.hash1 + MOD1 - 1) % MOD1 * INV1 % MOD1;
    a.hash2 = (a.hash2 + MOD2 - pows2[a.len]) % MOD2;
    b.hash2 = (b.hash2 + MOD2 - 1) % MOD2 * INV2 % MOD2;
    carry += 1;
  }
  hsh res;
  res.len = a.len + b.len;
  res.hash1 = (a.hash1 + b.hash1 * pows1[a.len]) % MOD1;
  res.hash2 = (a.hash2 + b.hash2 * pows2[a.len]) % MOD2;
  res.leading = a.len > 0 ? a.leading : b.leading;
  res.trailing = b.len > 0 ? b.trailing : a.trailing;
  res.pairs = a.pairs + b.pairs + carry;
  return res;
}

bool eq(hsh a, hsh b) {
  return a.pairs == b.pairs && a.hash1 == b.hash1 && a.hash2 == b.hash2;
}

hsh query(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
  int cl = cur * 2, cr = cur * 2 + 1, mid = (l + r) / 2;
  if (left <= l && r <= right) {
    return seg[cur];
  } else if (left >= r || l >= right) {
    return zero;
  } else {
    hsh q1 = query(left, right, cl, l, mid);
    hsh q2 = query(left, right, cr, mid, r);
    hsh res = add(q1, q2);
    return res;
  }
}

string s;
int n;
void build(int cur = 1, int l = 0, int r = MAXN) {
  int cl = cur * 2, cr = cur * 2 + 1, mid = (l + r) / 2;
  if (l + 1 == r) {
    seg[cur].len = 1;
    if (l < n && s[l] == '1') {
      seg[cur].leading = true;
      seg[cur].trailing = true;
      seg[cur].hash1 = 1;
      seg[cur].hash2 = 1;
    } else {
      seg[cur].hash1 = 2;
      seg[cur].hash2 = 2;
    }
  } else {
    build(cl, l, mid);
    build(cr, mid, r);
    seg[cur] = add(seg[cl], seg[cr]);
  }
}

int main() {
  cin.tie();
  ios_base::sync_with_stdio(0);
  pows1[0] = pows2[0] = 1;
  for (int i = 0; i + 1 < MAXN; ++i) {
    pows1[i + 1] = pows1[i] * A1 % MOD1;
    pows2[i + 1] = pows2[i] * A2 % MOD2;
  }
  cin >> n;
  cin >> s;
  build();
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; -- b;
    // printf("q(%d,%d)\n", a, a + c);
    hsh q1 = query(a, a + c);
    p(q1);
    // printf("q(%d,%d)\n", b, b + c);
    hsh q2 = query(b, b + c);
    p(q2);
    if (eq(q1, q2)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  p(seg[MAXN + 0]);
  p(seg[MAXN + 1]);
  p(add(seg[MAXN + 0], seg[MAXN + 1]));
  p(add(add(seg[MAXN + 0], seg[MAXN + 1]), seg[MAXN + 2]));
  p(seg[MAXN + 2]);
  p(seg[MAXN + 3]);
  p(seg[MAXN + 4]);
  p(add(seg[MAXN + 2], seg[MAXN + 3]));
  p(add(add(seg[MAXN + 2], seg[MAXN + 3]), seg[MAXN + 4]));
}