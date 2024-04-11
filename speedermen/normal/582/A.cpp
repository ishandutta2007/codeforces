#include <bits/stdc++.h>

using namespace std;

const int MaxN = 505;

int n, mat[MaxN * MaxN];
int a[MaxN];
char vis[MaxN * MaxN];
multiset < int > me;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  cin >> n;
  for (int i = 0; i < n * n; ++i) {
      scanf("%d", &mat[i]);
      me.insert(mat[i]);
  }
  sort(mat, mat + n * n);
  for (int d = 0; d < n; ++d) {
    a[d] = *me.rbegin();
    if (!me.empty()) {
      me.erase(--me.end());
    }
    for (int x = 0; x < d; ++x) {
      me.erase(me.find(gcd(a[x], a[d])));
      me.erase(me.find(gcd(a[x], a[d])));
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << endl;
  return 0;
}