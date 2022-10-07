#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1111;
int ed[MAXN];
int cnt[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    ++cnt[a];
    ++cnt[b];
    ed[a] ^= b;
    ed[b] ^= a;
  }

  for(int i = 0; i < n / 2; ++i) {
    vector<int> leafs;
    for (int j = 1; j <= n; ++j) {
      if (cnt[j] == 1) leafs.push_back(j);
    }
    int a = leafs[0], b = leafs[1];
    cout << "? " << a << " " << b << endl;
    int c;
    cin >> c;
    if (a == c || b == c) {
      cout << "! " << c << endl;
      return 0;
    }
    cnt[a] = -1;
    cnt[b] = -1;
    --cnt[ed[a]];
    --cnt[ed[b]];
    ed[ed[a]] ^= a;
    ed[ed[b]] ^= b;
  }
  for (int j = 1; j <= n; ++j) {
    if (cnt[j] >= 0) {
      cout << "! " << j << endl;
      return 0;
    }
  }
}