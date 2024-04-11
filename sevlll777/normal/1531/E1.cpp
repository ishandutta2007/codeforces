#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
string KEKW;
int pt = 0;

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
    if (KEKW[pt] == '0') {
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> KEKW;
  vector<int> P = meme(0, 16);
  vector<int> ans(16);
  for (int i = 0; i < 16; i++) {
    ans[P[i]] = i;
  }
  cout << 16 << '\n';
  for (auto x : ans) {
    cout << x + 1 << ' ';
  }
  cout << '\n';

}