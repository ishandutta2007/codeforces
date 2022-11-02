#include <bits/stdc++.h>
using namespace std;
#define M 1010000

char a[M], b[M];
int n, A[M], B[M];
int mp[256];

int main() {
  //freopen("in.txt", "r", stdin);
  mp['R'] = 0, mp['S'] = 1, mp['P'] = 2;
  scanf("%d", &n);
  scanf("%s %s", a, b);
  int la = strlen(a), lb = strlen(b);
  int len = la * lb / __gcd(la, lb);
  for (int i = 0; i < len; i++) a[i]  = a[i % la]; a[len] = 0;
  for (int i = 0; i < len; i++) b[i]  = b[i % lb]; b[len] = 0;
  for (int i = 0; i < len; i++) {
    if (i) A[i] = A[i - 1], B[i] = B[i - 1];
    int x = mp[a[i]], y = mp[b[i]];
    if (x != y) {
      if ((x + 1) % 3 == y) B[i]++; else A[i]++;
    }
  }
  int aa = 0, bb = 0;
  if (n % len) aa = A[(n % len) - 1], bb = B[(n % len) - 1];
  printf("%d %d\n", n / len * A[len - 1] + aa, n / len * B[len - 1] + bb);
}