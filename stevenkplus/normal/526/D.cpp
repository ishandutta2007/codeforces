#include <cstdio>

const int MAXN = 2000100;
char str[MAXN];

typedef long long ll;

const ll P1 = 103;
const ll P2 = 1E9 + 9;

ll hsh[MAXN];
ll pows[MAXN];


int prf[MAXN];
int ways[MAXN];
int N, K;

int main() {
  scanf("%d %d", &N, &K);
  scanf("%s", str);
  pows[0] = 1;
  for(int i = 0; i < N; ++i) {
    hsh[i + 1] = (P1 * hsh[i] + str[i]) % P2;
    pows[i + 1] = (pows[i] * P1) % P2;
  }

  for(int i = 1; i * K <= N; ++i) {
    bool good = true;
    for(int j = i; j <= i * K; j += i) {
      if ((hsh[j] - hsh[j - i] * pows[i] - hsh[i]) % P2 != 0) {
        good = false;
        break;
      }
    }

    if (good) {
      int base = i * K;
      int lo = base;
      int hi = base + i;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if ((hsh[mid] - hsh[base] * pows[mid - base] - hsh[mid - base]) % P2 == 0) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }

      ++prf[base];
      --prf[hi + 1];
    }
  }

  int ways = 0;
  for(int i = 1; i <= N; ++i) {
    ways += prf[i];
    if (ways >= 1) {
      printf("1");
    } else {
      printf("0");
    }
  }

  printf("\n");

}