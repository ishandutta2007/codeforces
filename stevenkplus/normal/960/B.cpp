#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1111;
int n, k;
long long a[MAXN], b[MAXN];

void go() {
  int k1, k2;
  cin >> n >> k1 >> k2;
  k = k1 + k2;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    a[i] -= b;
    if (a[i] < 0) a[i] *= -1;
  }
  for(int i = 0; i < k; ++i) {
    int b = 0;
    for(int j = 0; j < n; ++j) {
      if (a[j] > a[b]) b = j;
    }
    if (a[b] == 0) {
      a[b] += 1;
    } else {
      a[b] -= 1;
    }
  }
  long long res = 0;
  for(int i = 0; i < n; ++i) {
    res += a[i] * a[i];
  }
  cout << res << "\n";
}

int main() {
  go();
}