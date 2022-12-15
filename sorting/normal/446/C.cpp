#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int offset = 1<<19;
const int MAXN = offset;

const int mod = 1e9 + 9;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int T[2*offset];
int A[2*offset], B[2*offset];
int a[MAXN];
int f[MAXN][2];
int s[MAXN][2];

int calcsum(int len, int f1, int f2) {
  if (len == 0) return 0;
  return add(mul(s[len-1][0], f1), mul(s[len-1][1], f2));
}

void update(int i, int lo, int hi, int a, int b, int &F1, int &F2) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    T[i] = add(T[i], calcsum(hi-lo, F1, F2));
    A[i] = add(A[i], F1);
    B[i] = add(B[i], F2);
    
    int h = hi-lo;
    int NF1 = add(mul(f[h][0], F1), mul(f[h][1], F2));
    int NF2 = add(mul(f[h+1][0], F1), mul(f[h+1][1], F2));
    F1 = NF1, F2 = NF2;
    return;
  }

  update(i*2, lo, (lo+hi)/2, a, b, F1, F2);
  update(i*2+1, (lo+hi)/2, hi, a, b, F1, F2);
  T[i] = add(add(T[i*2], T[i*2+1]), calcsum(hi-lo, A[i], B[i]));
}


int query(int i, int lo, int hi, int a, int b, int F1, int F2) {
  if (lo >= b || hi <= a) return 0;
  if (lo >= a && hi <= b) return add(T[i], calcsum(hi-lo, F1, F2));
  F1 = add(F1, A[i]);
  F2 = add(F2, B[i]);

  int ans = 0, h = (hi-lo)/2;
  ans = add(ans, query(i*2, lo, (lo+hi)/2, a, b, F1, F2));
  int NF1 = add(mul(f[h][0], F1), mul(f[h][1], F2));
  int NF2 = add(mul(f[h+1][0], F1), mul(f[h+1][1], F2));
  
  ans = add(ans, query(i*2+1, (lo+hi)/2, hi, a, b, NF1, NF2));
  return ans;
}


int main(void) {
  f[0][0] = f[1][1] = 1;
  s[0][0] = s[1][0] = s[1][1] = 1;
  FOR(i, 2, MAXN) REP(j, 2) {
    f[i][j] = add(f[i-1][j], f[i-2][j]);
    s[i][j] = add(s[i-1][j], f[i][j]);
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  
  REP(i, n) T[offset + i] = a[i];
  for (int i = offset-1; i >= 0; --i)
    T[i] = add(T[i*2], T[i*2+1]);
  
  REP(i, m) {
    int tip, l, r;
    scanf("%d %d %d", &tip, &l, &r); --l, --r;

    int F1 = 1, F2 = 1;
    if (tip == 1) update(1, 0, offset, l, r+1, F1, F2);
    if (tip == 2) printf("%d\n", query(1, 0, offset, l, r+1, 0, 0));
  }
  return 0;
}