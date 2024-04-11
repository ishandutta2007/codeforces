#include <cstdio>
#include <cstdlib>

const int MAXN = 1001000;
const int MAXH = 20;

int H = 20;

int prand;
int bits = 0;
bool getb() {
  if (bits < 0) {
    prand = rand();
    bits = 31;
  }
  int ans = (prand >> bits) & 1;
  --bits;
  return ans;
}

int geth() {
  int ans = 0;
  while (ans + 1 < H && getb()) ++ans;
  return ans;
}

int nxt[MAXN][MAXH];
int len[MAXN][MAXH]; // #skipped + 1
int ans[MAXN];


int head = 1;

void ins(int nd, int pos) {
  int ht = geth();
  int cur = head;
  for(int h = H - 1; h >= 0; --h) {
    while (nxt[cur][h]) {
      if (len[cur][h] <= pos) {
        pos -= len[cur][h];
        cur = nxt[cur][h];
      } else {
        break;
      }
    }

//    printf("At %d %d\n", ans[cur], pos);
    if (h <= ht) {
      nxt[nd][h] = nxt[cur][h];
      len[nd][h] = len[cur][h] - pos;

      nxt[cur][h] = nd;
      len[cur][h] = pos + 1;
    } else {
      ++len[cur][h];
    }
  }
}

int pop() {
  int cur = head;
  int ans = nxt[cur][0];
  for(int h = H - 1; h >= 0; --h) {
    if (nxt[cur][h] && len[cur][h] == 1) {
      len[cur][h] = len[nxt[cur][h]][h];
      nxt[cur][h] = nxt[nxt[cur][h]][h];
    } else {
      --len[cur][h];
    }
  }
  return ans;
}

int X[MAXN], Y[MAXN];
int fin[MAXN];
bool vis[MAXN];

int N, M;
void disp() {
  int cur = head;
  for(int i = 0; i < N; ++i) {
    cur = nxt[cur][0];
    printf("%d ", ans[cur]);
  }
  printf("\n");
}

bool go() {
  scanf("%d %d", &N, &M);
  for(int i = 2; i <= N + 1; ++i) {
    ins(i, 0);
  }

  for(int i = 0; i < M; ++i) {
    scanf("%d %d", X + i, Y + i);
  }
  for(int i = M - 1; i >= 0; --i) {
    int x = X[i], y = Y[i];
    int front = pop();
    //printf("front = %d\n", front);
    //printf("ans[front] = %d\n", ans[front]);
    if (ans[front] && ans[front] != x) {
      return false;
    }
    ans[front] = x;
    ins(front, y - 1);
    //printf("inserting %d into %d\n", front, y - 1);
    //disp();
  }

  int cur = head;
  for(int i = 0; i < N; ++i) {
    cur = nxt[cur][0];
    fin[i] = cur;
  }
  for(int i = 0; i < N; ++i) {
    int a = ans[fin[i]];
    if (a) {
      if (vis[a]) return false;
      vis[a] = true;
    }
    //printf("ans[fin[%d]] = %d\n", i, ans[fin[i]]);
  }

  int n = 1;
  for(int i = 0; i < N; ++i) {
    if (!ans[fin[i]]) {
      while (vis[n]) ++n;
      ans[fin[i]] = n;
      ++n;
    }
    printf("%d ", ans[fin[i]]);
  }
  printf("\n");
  return true;
}

int main() {
  if (!go()) {
    printf("-1\n");
  }
  return 0;
}