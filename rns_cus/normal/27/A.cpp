#include <bits/stdc++.h>
using namespace std;
#define N 3030

bool vis[N];
int n;

int main() {
//  freopen("a.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    int j;
    scanf("%d", &j);
    vis[j] = 1;
  }
  for (int i = 1; i <= 3001; i ++) {
    if (!vis[i]) {
      printf("%d\n", i); return 0;
    }
  }
}