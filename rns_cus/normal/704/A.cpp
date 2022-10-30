#include <bits/stdc++.h>
using namespace std;
#define M 300010

vector <int> v[M], sto;

int en[M], n, Q, L, type, x, lst;
int vis[M];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &Q);
  for (int tc = 1; tc <= Q; tc++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &x);
      v[x].push_back(tc);
      lst++;
      sto.push_back(tc);
    }
    else if (type == 2) {
      scanf("%d", &x);
      for (int j = en[x]; j < v[x].size(); j++) {
        int u = v[x][j];
        if (!vis[u]) vis[u] = 1, lst--;
      }
      en[x] = v[x].size();
    }
    else {
      scanf("%d", &x);
      for (int j = L; j < x; j++) {
        int u = sto[j]; if (!vis[u]) vis[u] = 1, lst--;
      }
      L = max(L, x);
    }
    printf("%d\n", lst);
  }
}