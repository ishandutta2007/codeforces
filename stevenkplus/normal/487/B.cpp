#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100100;

int N, S, L;

int ar[MAXN];
int rgt[MAXN];

priority_queue<pii> qmax, qmin;

void put(int ind) {
  //printf("putting (%d, %d)\n", ind, ar[ind]);
  qmax.push(pii(ar[ind], ind));
  qmin.push(pii(-ar[ind], ind));
}

int askmax(int ind, int oth) {
  while (!qmax.empty() && (qmax.top().second < ind || qmax.top().second > oth)) {
    qmax.pop();
  }
  if (qmax.empty()) return -1;
  return qmax.top().first;
}

int askmin(int ind, int oth) {
  while (!qmin.empty() && (qmin.top().second < ind || qmin.top().second > oth)) {
    //printf("popping %d\n", qmin.top().second);
    qmin.pop();
  }

  int ret;
  if (qmin.empty()) ret = -1;
  else ret = -qmin.top().first;
  //printf("askmin: (%d, %d) => %d\n", ind, oth, ret);
  return ret;
}

int main() {
  scanf("%d %d %d", &N, &S, &L);

  int tot = 0;

  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  if (L > N) {
    printf("-1\n");
    return 0;
  }

  int cur = 0;
  for(cur = 0; cur < L; ++cur) {
    put(cur);
  }

  if (askmax(0, N) - askmin(0, N) > S) {
    printf("-1\n");
    return 0;
  }

  for(int i = 0; i < N; ++i) {
    if (i)
      rgt[i] = rgt[i - 1];
    for (; askmax(i, N) - askmin(i, N) <= S; ++cur) {
      rgt[i] = cur;
      if (cur >= N) break;
      put(cur);
    }
  }

  //printf("RGT\n");
  for(int i = 0; i < N; ++i) {
    //printf("%d: %d\n", i, rgt[i]);
  }

  //printf("DP\n");


  while (!qmin.empty()) qmin.pop();
  while (!qmax.empty()) qmax.pop();

  ar[N] = 0;
  ////printf("starting.\n");
  for(int i = N - 1; i >= 0; --i) {
    if (i + L <= N && ar[i + L] != -1) {
      //printf("putting %d\n", i + L);
      put(i + L);
    }
    int val = askmin(0, rgt[i]);
    ar[i] = val;
    if (ar[i] != -1) ++ar[i];
    //printf("%d: %d\n", i, ar[i]);
  }

  printf("%d\n", ar[0]);
  return 0;
}