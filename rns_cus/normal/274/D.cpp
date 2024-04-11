#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define B 330

typedef pair<int, int> pii;

int n, m;
vector <int> a[N];
set <pii> s[N];
set <pii> :: iterator it;
int vis[N];
int ans[N], cnt;

bool dfs(int r) {
  vis[r] = 1;
  while(1) {
    int i, j;
    for(i = 0; i < n; i ++) if(a[i][r] != -1) {
      it = s[i].end();
      it --;
      if(it -> first > a[i][r]) {
        j = it -> second;
        break;
      }
    }
    if(i < n) {
      if(vis[j]) return 0;
      if(!dfs(j)) return 0;
    } else break;
  }
  ans[cnt ++] = r + 1;
  for(int i = 0; i < n; i ++) {
    s[i].erase(pii(a[i][r], r));
  }
  return 1;
}

int run() {
  for(int i = 0; i < m; i ++) if(!vis[i]&& !dfs(i)) return 0;
  for(int i = m - 1; i >= 0; i --) printf("%d ", ans[i]); puts("");
  return 1;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i ++) {
    for(int x, j = 0; j < m; j ++) {
      scanf("%d", &x);
      a[i].push_back(x);
      s[i].insert(pii(x, j));
    }
  }
  if(!run()) puts("-1");
  return 0;
}