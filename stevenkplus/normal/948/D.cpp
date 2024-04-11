#include <cstdio>

const int MAXN = 300100 * 30;
int inp[MAXN];
int trie[MAXN][2];
int cnt[MAXN];

int cntTrie = 0;
int get(int node, int i) {
  int &ret = trie[node][i];
  if (!ret) ret = ++cntTrie;
  return ret;
}

bool has(int node, int i) {
  if (!trie[node][i]) return false;
  return cnt[trie[node][i]] > 0;
}

int query(int x) {
  int cur = 0;
  int ans = 0;
  for(int j = 0; j < 30; ++j) {
    int bit = (x >> (29 - j)) & 1;
    if (has(cur, bit)) {
      ans = ans * 2 + bit;
      cur = get(cur, bit);
    } else {
      ans = ans * 2 + (1 - bit);
      cur = get(cur, 1 - bit);
    }
  }
  return ans;
}

int main() {
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", inp + i);
  }
  for(int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    int cur = 0;
    for(int j = 0; j < 30; ++j) {
      cur = get(cur, (x >> (29 - j)) & 1);
      ++cnt[cur];
    }
  }

  for(int i = 0; i < N; ++i) {
    int x = query(inp[i]);
    printf("%d ", x ^ inp[i]);
    int cur = 0;
    for(int j = 0; j < 30; ++j) {
      cur = get(cur, (x >> (29 - j)) & 1);
      --cnt[cur];
    }
  }
  printf("\n");
}