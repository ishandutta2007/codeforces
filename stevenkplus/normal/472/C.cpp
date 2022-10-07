#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 100100;

string f[MAXN], l[MAXN];
int P[MAXN];
int N;

string cur;

bool ain() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    cin >> f[i] >> l[i];
  }

  cur = "";
  for(int i = 0; i < N; ++i) {
    scanf("%d", P + i);
    --P[i];
    if (f[P[i]] >= cur) {
      if (l[P[i]] < f[P[i]] && l[P[i]] >= cur) {
        cur = l[P[i]];
      } else {
        cur = f[P[i]];
      }
    } else if (l[P[i]] >= cur) {
      cur = l[P[i]];
    } else {
      return false;
    }
  }

  return true;
}


int main() {
  if (ain()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}