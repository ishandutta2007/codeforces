#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

void error() {
  puts("0");
  exit(0);
}

const int N = 1234567;

int p[N], fact[N], group[N], pr[N];
vector <int> d[N];
int link_a[N], link_b[N];
int zeros[N];
int aux[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
  }
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 1; i <= n; i++) {
    group[i] = n / i;
  }
  group[1] = 1;
  for (int i = 1; i <= n; i++) {
    pr[i] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (pr[i] == i) {
      for (int j = i + i; j <= n; j += i) {
        if (pr[j] == j) {
          pr[j] = i;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    d[i].clear();
    while (tmp > 1) {
      int num = pr[tmp];
      d[i].push_back(num);
      while (tmp % num == 0) {
        tmp /= num;
      }
    }
  }
  d[1].push_back(1);
  for (int i = 1; i <= n; i++) {
    link_a[i] = 0;
    link_b[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] != 0) {
      int si = d[i].size();
      int spi = d[p[i]].size();
      if (si != spi) {
        error();
      }
      for (int j = 0; j < si; j++) {
        int x = d[i][j];
        int y = d[p[i]][j];
        if (group[x] != group[y]) {
          error();
        }
        if (link_a[x] == 0 && link_b[y] == 0) {
          link_a[x] = y;
          link_b[y] = x;
          continue;
        }
        if (link_a[x] != y || link_b[y] != x) {
          error();
        }
      }
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    zeros[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (pr[i] == i && link_a[i] == 0) {
      zeros[group[i]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (zeros[i] > 0) {
      ans = mul(ans, fact[zeros[i]]);
    }
  }
  for (int i = 1; i <= n; i++) {
    aux[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] != 0) {
      continue;
    }
    int h = 1;
    for (int j = 0; j < (int) d[i].size(); j++) {
      h *= d[i][j];
    }
    aux[h]++;
  }
  for (int i = 1; i <= n; i++) {
    if (aux[i] > 0) {
      ans = mul(ans, fact[aux[i]]);
    }
  }
  printf("%d\n", ans);
  return 0;
}