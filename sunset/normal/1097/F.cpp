#include <bits/stdc++.h>

using namespace std;

const int MAX = 7001;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> mu(MAX, 1);
  for (int i = 2; i < MAX; ++i) {
    for (int j = i * i; j < MAX; j += i * i) {
      mu[j] = 0;
    }
  }
  vector<bitset<MAX>> divisors(MAX);
  vector<bitset<MAX>> multiples(MAX);
  for (int i = 1; i < MAX; ++i) {
    for (int j = i; j < MAX; j += i) {
      divisors[j][i] = true;
      if (mu[j / i]) {
        multiples[i][j] = true;
      }
    }
  }
  int n, q;
  cin >> n >> q;
  vector<bitset<MAX>> a(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, v;
      cin >> x >> v;
      --x;
      a[x] = divisors[v];
    } else if (type == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      --z;
      a[x] = a[y] ^ a[z];
    } else if (type == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      --z;
      a[x] = a[y] & a[z];
    } else {
      int x, v;
      cin >> x >> v;
      --x;
      cout << (a[x] & multiples[v]).count() % 2;
    }
  }
  cout << "\n";
  return 0;
}