#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 101;
const int MAXS = 1011;
const int inf = 1000 << 20;


int adj[MAXN][MAXN];
int L[MAXS], A[MAXS], F[MAXS];;
int X[MAXS], D[MAXS];
int match[MAXS][MAXS];

bool vis[MAXS];
int to[MAXS];
int from[MAXS];
int matches = 0;
int B;

void reset() {
  for(int i = 0; i < MAXS; ++i) {
    vis[i] = 0;
  }
}

bool go(int i) {
  for(int j = 0; j < B; ++j) {
    if (vis[j]) continue;
    if (match[i][j]) {
      vis[j] = true;
      if (from[j] != -1) {
        if (go(from[j])) {
          // printf("go %d %d\n", i, j);
          from[j] = i;
          to[i] = j;
          return true;
        }
      } else {
        // printf("free %d %d\n", i, j);
        from[j] = i;
        to[i] = j;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      adj[i][j] = inf;
    }
    adj[i][i] = 0;
  }
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a][b] = 1;
  }

  for(int k = 0; k < n; ++k) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }

  int s, b, k, h;
  cin >> s >> b >> k >> h;
  B = b;
  for(int i = 0; i < s; ++i) {
    cin >> L[i] >> A[i] >> F[i];
    --L[i];
  }
  for(int i = 0; i < b; ++i) {
    cin >> X[i] >> D[i];
    --X[i];
  }
  for(int i = 0; i < s; ++i) {
    for(int j = 0; j < b; ++j) {
      if (adj[L[i]][X[j]] <= F[i] && A[i] >= D[j]) {
        // cout << "match " << i << "," << j << "\n";
        match[i][j] = 1;
      }
    }
  }

  int cnt = 0;
  for(int i = 0; i < b; ++i) {
    from[i] = -1;
  }
  for(int i = 0; i < s; ++i) {
    reset();
    if (go(i)) {
      ++cnt;
    }
  }
  ll val = ll(k) * cnt;
  ll oth = ll(h) * s;
  if (oth < val) val = oth;
  cout << val << "\n";
}