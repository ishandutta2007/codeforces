#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
  char ch; x = 0;
  int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 200005;
struct seg{
  int l, r, c;
}a[N];
struct segtree{
  int f[N * 8], tag[N * 8];
  int qmax(int x, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return f[x];
    int mid = (l + r) >> 1, res = 0;
    if(ql <= mid) upmax(res, qmax(x << 1, l, mid, ql, qr));
    if(qr > mid) upmax(res, qmax(x << 1 | 1, mid + 1, r, ql, qr));
    return res + tag[x];
  }
  void inc(int x, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
      f[x] += v, tag[x] += v;
      return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid) inc(x << 1, l, mid, ql, qr, v);
    if(qr > mid) inc(x << 1 | 1, mid + 1, r, ql, qr, v);
    f[x] = max(f[x << 1], f[x << 1 | 1]) + tag[x];
  }
}f[2];
int p[N * 2], pc = 0;

int main(){
//  File("cf1389f");
  int n;
  gi(n);
  for(int i=1; i<=n; i++){
    gi(a[i].l), gi(a[i].r), gi(a[i].c);
    p[++pc] = a[i].l, p[++pc] = a[i].r;
    --a[i].c;
  }
  sort(p + 1, p + 1 + pc);
  pc = unique(p + 1, p + 1 + pc) - p - 1;
  for(int i=1; i<=n; i++){
    a[i].l = lower_bound(p + 1, p + 1 + pc, a[i].l) - p;
    a[i].r = lower_bound(p + 1, p + 1 + pc, a[i].r) - p;
  }
  sort(a + 1, a + 1 + n, [](seg a, seg b){
    if(a.r == b.r) return a.c < b.c;
    return a.r < b.r;
  });

  int dp = 0, res = 0;
  for(int i=1; i<=n; i++){
    if(a[i].r != a[i - 1].r || a[i].c != a[i - 1].c)
      dp = 0;
    f[a[i].c ^ 1].inc(1, 0, pc, 0, a[i].l - 1, 1);
    upmax(dp, f[a[i].c ^ 1].f[1]);
    if(a[i].r != a[i + 1].r || a[i].c != a[i + 1].c)
      f[a[i].c].inc(1, 0, pc, a[i].r, a[i].r, dp);
    upmax(res, dp);
  }
  printf("%d\n", res);
  return 0;
}