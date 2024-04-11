#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
string KEKW, bim;
int pt = 0;
vector<int> a, b;

vector<int> meme(int l, int r) {
  if (r - l == 1) {
    return {l};
  }
  if (l >= r) {
    return {};
  }
  int m = (l + r) / 2;
  vector<int> a = meme(l, m);
  for (auto x : meme(m, r)) {
    a.pb(x);
  }
  vector<int> heh;
  int i = l;
  int j = m;
  while (i < m && j < r) {
    if (pt >= (int) KEKW.size() || KEKW[pt] == '0') {
      heh.pb(a[i - l]);
      i++;
    } else {
      heh.pb(a[j - l]);
      j++;
    }
    pt++;
  }
  while (i < m) {
    heh.pb(a[i - l]);
    i++;
  }
  while (j < r) {
    heh.pb(a[j - l]);
    j++;
  }
  return heh;
}

void merge(int l, int r) {
  if (r - l <= 1) return;
  int m = (l + r) / 2;
  merge(l, m);
  merge(m, r);
  int i = l, j = m, k = l;
  while (i < m && j < r) {
    if (a[i] < a[j]) {
      bim += '0';
      b[k] = a[i];
      i++;
    } else {
      bim += '1';
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while (i < m) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j < r) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (int p = l; p < r; p++) {
    a[p] = b[p];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> KEKW;
  int l = 1, r = 100009;
  while (r - l > 1) {
    int len = (l + r) / 2;
    pt = 0;
    vector<int> P = meme(0, len);
    vector<int> ans(len);
    for (int i = 0; i < len; i++) {
      ans[P[i]] = i;
    }
    b.assign(len, 0);
    bim = "";
    a = ans;
    merge(0, len);
    if (bim == KEKW) {
      cout << len << '\n';
      for (auto x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
      exit(0);
    }
    if (bim.size() < KEKW.size()) {
      l = len;
    } else {
      r = len;
    }
  }

}