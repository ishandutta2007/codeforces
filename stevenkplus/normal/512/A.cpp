#include <cstdio>

const int MAXC = 300;
const int MAXN = 110;

char str[MAXN][MAXN];
int adj[MAXC][MAXC];
int indeg[MAXC];
bool vis[MAXC];

int N;

char ans[MAXN];

bool go(char *a, char *b) {
  while (*a == *b) {
    ++a;
    ++b;
  }

  if (!(*b)) {
    return false;
  }

  if (*a) {
    ++adj[*a][*b];
    ++indeg[*b];
  }
  return true;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%s", str[i]);
  }

  bool good = true;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < i; ++j) {
      good = good & go(str[j], str[i]);
    }
  }

  if (!good) {
    printf("Impossible\n");
    return 0;
  }

  int pos = 0;
  for(int i = 0; i < 26; ++i) {
    char nxt = 0;
    for(char c = 'a'; c <= 'z'; ++c) {
      if (!vis[c] && indeg[c] == 0) {
        nxt = c;
        break;
      }
    }

    if (nxt) {
      vis[nxt] = true;
      ans[i] = nxt;
      for(char c = 'a'; c <= 'z'; ++c) {
        if (adj[nxt][c]) {
          indeg[c] -= adj[nxt][c];
        }
      }
    } else {
      printf("Impossible\n");
      return 0;
    }
  }

  printf("%s\n", ans);
}