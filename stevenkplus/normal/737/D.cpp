#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 4010;
const int MAXK = 100;
const int inf = 1000 << 20;

int ar[MAXN];
int prefSums[MAXN];
int suffSums[MAXN];
int DP[2][2][MAXN][MAXN];

typedef pair<int, int> pii;
typedef pair<pii, pii> state;
// state = pair(pair(k, t), pair(a, b))

#define getK(s) (s.first.first)
#define getT(s) (s.first.second)
#define getA(s) (s.second.first)
#define getB(s) (s.second.second)
#define S(k, t, a, b) (state(pii(k,t), pii(a, b)))
#define D(s) DP[(getK(s))&1][getT(s)][getA(s)][getB(s)]

int N;

state ns[10];
int nextStateCnt = 0;
static inline void next(state s) {
  nextStateCnt = 0;
  int k = getK(s);
  int t = getT(s);
  int a = getA(s);
  int b = getB(s);
  if (t == 0) {
    if (a + k + b <= N) {
      ns[nextStateCnt++] = (S(k, 1, a + k, b));
    }
    if (a + k + 1 + b <= N) {
      ns[nextStateCnt++] = (S(k + 1, 1, a + k + 1, b));
    }
  } else {
    if (a + b + k <= N) {
      ns[nextStateCnt++] = (S(k, 0, a, b + k));
    }
    if (a + b + k + 1 <= N)  {
      ns[nextStateCnt++] = (S(k + 1, 0, a, b + k + 1));
    }
  }
}

void disp(state s) {
  printf("state(k=%d,t=%d,a=%d,b=%d)\n",
      getK(s), getT(s), getA(s), getB(s));
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  for(int i = 0; i < N; ++i) {
    prefSums[i + 1] = prefSums[i] + ar[i];
    suffSums[i + 1] = suffSums[i] + ar[N - 1 - i];
  }

  for(int k = MAXK; k >= 1; --k) {
    for(int a = N; a >= 0; --a) {
      //if (a < (k / 2) * (k / 2)) continue;
      //if (a + a - k > N) continue;
      for(int b = a + k; b >= a - k; --b) {
        for(int t = 0; t < 2; ++t) {
          if (b >= 0 && a + b <= N) {
            state s = S(k, t, a, b);
            //printf("on "); disp(s);
            next(s);
            if (nextStateCnt == 0) {
              //printf("base case.\n");
              //disp(s);
              // the base case
              if (t == 0) {
                D(s) = prefSums[a] - suffSums[b];
              } else {
                D(s) = suffSums[b] - prefSums[a];
              }
            } else {
              D(s) = -inf;
              for(int i = 0; i < nextStateCnt; ++i) {
                state t = ns[i];
                if (-D(t) > D(s)) {
                  D(s) = -D(t);
                }
              }
            }
            //printf("val=%d\n", D(s));
          }
        }
      }
    }
  }

  int ans = D(S(1, 0, 0, 0));
  printf("%d\n", ans);
}