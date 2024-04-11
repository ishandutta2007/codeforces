#include <cstdio>

const int MAXN = 100100;

char S[MAXN]; // 1-indexed
char T[MAXN];

int aS[MAXN], aT[MAXN]; // aS[i] = trailing #A at i (incl. S[i])
int bS[MAXN], bT[MAXN]; // prefix sums of #Bs

bool go() {
  int leftS, rightS, leftT, rightT;
  scanf("%d %d %d %d", &leftS, &rightS, &leftT, &rightT);
  int lengthS = rightS - leftS + 1;
  int lengthT = rightT - leftT + 1;
  int as = aS[rightS]; if (as > lengthS) as = lengthS;
  int at = aT[rightT]; if (at > lengthT) at = lengthT;

  int bs = bS[rightS] - bS[leftS - 1];
  int bt = bT[rightT] - bT[leftT - 1];

  // printf("as,at,bs,bt: %d,%d,%d,%d\n", as, at, bs, bt);
  if (bs % 2 != bt % 2) {
    return false;
  }
  if (bs > bt) {
    return false;
  }

  if (as < at) {
    return false;
  }
  if (bs == bt) {
    if (as % 3 != at % 3) {
      return false;
    }
  } else {
    if (bs == 0 && as == at) {
      return false;
    }
  }
  return true;
}

void goA(char *s, int *ar) {
  int run = 0;
  for(int i = 1; s[i]; ++i) {
    if (s[i] == 'A') ++run;
    else run = 0;
    ar[i] = run;
  }
}

void goB(char *s, int *ar) {
  int run = 0;
  for(int i = 1; s[i]; ++i) {
    if (s[i] == 'B' || s[i] == 'C') ++run;
    ar[i] = run;
  }
}

int main() {
  scanf("%s", S + 1);
  scanf("%s", T + 1);

  goA(S, aS);
  goA(T, aT);
  goB(S, bS);
  goB(T, bT);
  int q;
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    if (go()) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
}