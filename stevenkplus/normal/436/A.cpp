#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2010;

int N, X;

pii A[MAXN];
pii B[MAXN];
bool visa[MAXN];
bool visb[MAXN];
int a, b;

int go(int on) {
  int cur = 0;
  int h = X;
  for(int i = 0; i < a; ++i) {
    visa[i] = false;
  }
  for(int i = 0; i < b; ++i) {
    visb[i] = false;
  }

  while (true) {
    int bst = -1;
    if (on == 0) {
      for(int i = 0; i < a; ++i) {
        if (visa[i]) continue;
        if (A[i].first > h) continue;
        if (bst == -1 || A[i].second > A[bst].second) bst = i;
      }
      if (bst == -1) break;
      ++cur;
      visa[bst] = true;
      h += A[bst].second;
      on = 1;
    } else {
      for(int i = 0; i < b; ++i){ 
        if (visb[i]) continue;
        if (B[i].first > h) continue;
        if (bst == -1 || B[i].second > B[bst].second) bst = i;
      }
      if (bst == -1) break;
      ++cur;
      visb[bst] = true;
      h += B[bst].second;
      on = 0;
    }
  }
  return cur;
}

int main() {
  scanf("%d %d", &N, &X);
  for(int i = 0; i < N; ++i) {
    int t, h, m;
    scanf("%d %d %d", &t, &h, &m);
    if (t == 0) {
      A[a] = pii(h, m);
      ++a;
    } else {
      B[b] = pii(h, m);
      ++b;
    }
  }

  int x = go(0);
  int y = go(1);
  int ans = x;
  if (y > ans) ans = y;
  printf("%d\n", ans);
  return 0;
}