#include <cstdio>
#include <cstring>

const int S = 1 << 7;
const int MOD = 1E9 + 7;

int W[7];

typedef long long ll;
ll cur[S];
ll tmp[S];

void clear() { memset(tmp, 0, sizeof(tmp)); }
void copy() { for(int i = 0; i < S; ++i) { cur[i] = tmp[i]; } }

void trans(int prv, int ht) {
  clear();
  int msk = 0;
  for(int i = prv; i < ht; ++i) {
    msk |= 1 << i;
  }

//  printf("msk = %d\n", msk);
  for(int i = 0; i < (1 << prv); ++i) {
    tmp[i | msk] = cur[i];
  }
  copy();
}


bool on(int msk, int x) {
  if (x < 0) return 1;
  return (msk >> x) & 1;
}

bool ok(int lft, int rgt, int mid, int h) {
  for(int i = 0; i < h; ++i) {
    if (on(lft, i) && on(rgt, i) && on(mid, i) && on(mid, i - 1)) {
      return false;
    }
  }
  return true;
}

ll matr[S][S];
ll tmpm[S][S];

void square(int size) {

  memset(tmpm, 0, sizeof(tmpm));
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      for(int k = 0; k < size; ++k) {
        tmpm[i][j] += matr[i][k] * matr[k][j];
        tmpm[i][j] %= MOD;
      }
    }
  }
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      matr[i][j] = tmpm[i][j];
    }
  }

}

int main() {
  cur[0] = 1;
  int ht = 0;
  for(int h = 1; h <= 7; ++h) {
    scanf("%d", W + h);
    if (W[h] > 0) {
      trans(ht, h);
      ht = h;

      memset(matr, 0, sizeof(matr));
      for(int i = 0; i < (1 << h); ++i) { // left-side edges
        for(int j = 0; j < (1 << h) ; ++j) { // right-side edges
          for(int k = 1 << (h - 1); k < (1 << h); ++k) { // middle edges, top must be filled

            if (ok(i, j, k, h)) {
              ++matr[i][j];
            }
          }
        }
      }

      for(int p = 0; p < 30; ++p) {
        if (on(W[h], p)) {
          clear();
          for(int i = 0; i < (1 << h); ++i) {
            for(int j = 0; j < (1 << h); ++j) {
              tmp[j] += matr[i][j] * cur[i];
              tmp[j] %= MOD;
            }
          }

          copy();
        }

        square(1 << h);
      }
    }
  }

  int ans = int(cur[(1 << ht) - 1]);
  printf("%d\n", ans);
}