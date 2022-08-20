#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, x[N], y[N], oper[N], answer[N], result[N];

void dfs(int u) {
  if (!oper[u]) {
    answer[u] = x[u];
  } else if (oper[u] == 1) {
    dfs(x[u]);
    dfs(y[u]);
    answer[u] = answer[x[u]] & answer[y[u]];
  } else if (oper[u] == 2) {
    dfs(x[u]);
    dfs(y[u]);
    answer[u] = answer[x[u]] | answer[y[u]];
  } else if (oper[u] == 3) {
    dfs(x[u]);
    dfs(y[u]);
    answer[u] = answer[x[u]] ^ answer[y[u]];
  } else {
    dfs(x[u]);
    answer[u] = !answer[x[u]];
  }
}

void make(int u, int value) {
  if (!oper[u]) {
    result[u] = value;
  } else if (oper[u] < 4) {
    make(x[u], value);
    make(y[u], value);
  } else {
    make(x[u], value);
  }
}

void down(int u) {
  if (!oper[u]) {
    result[u] = !answer[1];
  } else if (oper[u] == 1) {
    if (!answer[y[u]]) {
      make(x[u], answer[1]);
    } else {
      down(x[u]);
    }
    if (!answer[x[u]]) {
      make(y[u], answer[1]);
    } else {
      down(y[u]);
    }
  } else if (oper[u] == 2) {
    if (answer[y[u]]) {
      make(x[u], answer[1]);
    } else {
      down(x[u]);
    }
    if (answer[x[u]]) {
      make(y[u], answer[1]);
    } else {
      down(y[u]);
    }
  } else if (oper[u] == 3) {
    down(x[u]);
    down(y[u]);
  } else {
    down(x[u]);
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char type[10];
    scanf("%s", type);
    if (type[0] == 'I') {
      scanf("%d", &x[i]);
    } else if (type[0] == 'A') {
      oper[i] = 1;
      scanf("%d %d", &x[i], &y[i]);
    } else if (type[0] == 'O') {
      oper[i] = 2;
      scanf("%d %d", &x[i], &y[i]);
    } else if (type[0] == 'X') {
      oper[i] = 3;
      scanf("%d %d", &x[i], &y[i]);
    } else {
      oper[i] = 4;
      scanf("%d", &x[i]);
    }
  }
  dfs(1);
  down(1);
  for (int i = 1; i <= n; ++i) {
    if (!oper[i]) {
      putchar(result[i] + '0');
    }
  }
  putchar(10);
  return 0;
}