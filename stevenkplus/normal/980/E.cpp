#include <bits/stdc++.h>
using namespace std;

#define repi(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i) 
int n, k;

const int MAXN = 1111111;
vector<int> ed[MAXN];
int pars[MAXN][33];
bool took[MAXN];

void dfs(int cur, int p = 0) {
  pars[cur][0] = p;
  repi(i, ed[cur]) {
    if (*i != p) {
      dfs(*i, cur);
    }
  }
}

void take(int x) {
  while (!took[x]) {
    took[x] = true;
    --k;
    x = pars[x][0];
  }
}

int getDist(int x) {
  int ans = 0;
  for(int j = 30; j >= 0; --j) {
    if (!took[pars[x][j]]) {
      ans |= (1 << j);
      x = pars[x][j];
    }
  }
  return ans + 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k; k = n - k;
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  dfs(n);
  pars[n][0] = n;
  for(int i = 0; i < 30; ++i) {
    for(int j = 1; j <= n; ++j) {
      pars[j][i + 1] = pars[pars[j][i]][i];
    }
  }

  take(n);
  for(int i = n; i >= 1; --i) {
    int dst = getDist(i);
    if (dst <= k) {
      take(i);
    }
  }


  for(int i = 1; i <= n; ++i) {
    if (!took[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}