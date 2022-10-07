#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 222;

int vis[MAXN][MAXN][MAXN];
char str[MAXN];
int N;
void visit(vector<int> cur) {
  int &v = vis[cur[0]][cur[1]][cur[2]];
  if (v) return;
  v = 1;

  for(int i = 0; i < 3; ++i) {
    if (cur[i] >= 2) {
      vector<int> nxt = cur;
      --nxt[i];
      visit(nxt);
    }
  }

  for(int i = 0; i < 3; ++i) {
    for(int j = i + 1; j < 3; ++j) {
      int k = 3 - i - j;
      if (cur[i] >= 1 && cur[j] >= 1) {
        vector<int> nxt = cur;
        --nxt[i];
        --nxt[j];
        ++nxt[k];
        visit(nxt);
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  scanf("%s", str);
  vector<int> cur(3);
  for(int i = 0; i < N; ++i) {
    if (str[i] == 'B') ++cur[0];
    else if (str[i] == 'G') ++cur[1];
    else ++cur[2];
  }
  visit(cur);


  if (vis[1][0][0]) printf("B");
  if (vis[0][1][0]) printf("G");
  if (vis[0][0][1]) printf("R");
  printf("\n");
  return 0;
}