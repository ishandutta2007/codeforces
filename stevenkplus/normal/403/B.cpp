#include <cstdio>

int gcd(int a, int b) {
  if (a == 0) return b;
  else return gcd(b % a, a);
}


const int MAXN = 5010;
const int PRIMES = 10100;
const int MAXV = 100100;

int ar[MAXN];
int B[MAXN];
int N, M;

int prm[PRIMES];
int cnt = 0;
bool sv[MAXV];
void sieve() {
  for(int i = 2; i < MAXV; ++i) {
    if (!sv[i]) {
      prm[cnt] = i;
      ++cnt;

      for(int k = i; k <= (MAXV - 1) / i; ++k) {
        sv[i * k] = true;
      }
    }
  }
}

int score(int num) {
  //printf("score(%d) = ", num);
  int pos = 0;
  int ret = 0;
  for(int i = 0; i < cnt; ++i) {
    int p = prm[i];
    while (pos < M && B[pos] < p) ++pos;
    while (num % p == 0) {
      num /= p;
      if (B[pos] == p) --ret;
      else ++ret;
    }
  }
  if (num > 1) {
    while (pos < M && B[pos] < num) ++pos;
    if (B[pos] == num) --ret;
    else ++ret;
  }
  //printf("%d\n", ret);
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  for(int i = 0; i < M; ++i) {
    scanf("%d", B + i);
  }

  sieve();
  for(int i = N; i > 0; --i) {
    int g = ar[0];
    for(int j = 0; j < i; ++j) {
      g = gcd(g, ar[j]);
    }
    int s = score(g);
    if (s < 0) {
      for(int j = 0; j < i; ++j) {
        ar[j] /= g;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    ans += score(ar[i]);
  }

  printf("%d\n", ans);
  return 0;
}