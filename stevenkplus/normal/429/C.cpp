#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 25;
const int MAXM = 14;
bool vis[MAXM][MAXM][1 << MAXM][MAXN][3]; // pos, numchilds, used not 1, 1s left

int N, M;

int ar[MAXN];

bool ans = false;
void go(int cur, int ch, int msk, int ones, int cnt) {
  if (cur == M) {
    if (msk == (1 << (M - 1)) - 1 && ones == 0) {
      ans = true;
    }
    return;
  }

  if (ch + 1 > ar[cur]) return;
  if (ch + 1 == ar[cur]) {
    if (cnt >= 2) {
      go(cur + 1, 0, msk, ones, 0);
    }
    return;
  }

  bool &v = vis[cur][ch][msk][ones][cnt];
  if (v) return;
  v = true;

  if (ones) {
    go(cur, ch + 1, msk, ones - 1, cnt + 1);
  }

  for(int i = 0; i < cur; ++i) {
    if (!((msk >> i) & 1)) {
      go(cur, ch + ar[i], msk | (1 << i), ones, cnt + 1);
    }
  }
}

bool go() {
  scanf("%d", &N);
  int ones = 0;
  for(int i = 0; i < N; ++i) {
    int nxt;
    scanf("%d", &nxt);
    if (nxt == 1) ++ones;
    else {
      ar[M] = nxt;
      ++M;
    }
  }
  if (N == 1) {
    return ones == 1;
  }

  sort(ar, ar + M);
  if (ones <= M) {
    return false;
  }

  go(0, 0, 0, ones, 0);


  return ans;
}

int main() {
  if (go()) printf("YES\n");
  else printf("NO\n");
  return 0;
}