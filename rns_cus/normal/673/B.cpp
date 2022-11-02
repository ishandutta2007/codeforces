#include <bits/stdc++.h>
using namespace std;
#define M 100010

vector <int> adj[M];
int n, m;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  if (!m) return printf("%d\n", n - 1), 0;
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    adj[x].push_back(y); adj[y].push_back(x);
  }
  int L = 2, bf = 0;
  while (!bf && L <= n) {
    for (int i = 0; i < adj[L].size(); i++) {
      if (adj[L][i] < L) bf = 1;
    }
    if (!bf) L++;
  }
  int R = n - 1;
  bf = 0;
  while (!bf && R) {
    for (int i = 0; i < adj[R].size(); i++) {
      if (adj[R][i] > R) bf = 1;
    }
    if (!bf) R--;
  }
  printf("%d\n", max(0, L - R));
}