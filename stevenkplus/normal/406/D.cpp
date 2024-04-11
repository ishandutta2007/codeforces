#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100100;
const int MAXK = 17;

typedef long long ll;

int X[MAXN];
ll Y[MAXN];

int N, M;

int par[MAXN][MAXK];
int dpth[MAXN];

int Q[MAXN];
int ql = 0, qr = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    cin >> X[i] >> Y[i];
  }

  for(int i = N; i > 0; --i) {
    while (ql + 1 < qr) {
      int a = Q[qr - 1], b = Q[qr - 2];
      if ((Y[b] - Y[i]) * (X[a] - X[i]) > (Y[a] - Y[i]) * (X[b] - X[i])) {
        --qr;
      } else break;
    }
    if (ql < qr) {
      par[i][0] = Q[qr - 1];
      dpth[i] = dpth[Q[qr - 1]] + 1;
    } else par[i][0] = i;
    Q[qr] = i;
    ++qr;
  }

  for(int k = 0; k + 1 < MAXK; ++k) {
    for(int i = 1; i <= N; ++i) {
      par[i][k + 1] = par[par[i][k]][k];
    }
  }

  cin >> M;
  for(int q = 0; q < M; ++q) {
    int a, b;
    cin >> a >> b;

    if (dpth[a] < dpth[b]) swap(a, b);
    for(int i = MAXK - 1; i >= 0; --i) {
      if (dpth[par[a][i]] >= dpth[b]) {
        a = par[a][i];
      }
    }

    for(int i = MAXK - 1; i >= 0; --i) {
      if (par[a][i] != par[b][i]) {
        a = par[a][i];
        b = par[b][i];
      }
    }

    if (a != b) {
      a = par[a][0];
      b = par[b][0];
    }
    if (a != b) printf("what\n");

    printf("%d ", a);
  }
  printf("\n");
  return 0;
}