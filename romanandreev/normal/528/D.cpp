#include <bits/stdc++.h>

using namespace std;

typedef double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define problem_name "a"

const int maxn = (1 << 19) + 1;
const ld PI = acos((ld)-1);
struct pnt {
  ld x, y;
  pnt() {    
  }
  pnt(ld x, ld y):x(x), y(y) {
  }
  inline pnt operator * (const pnt& a) {
    return pnt(x * a.x - y * a.y, x * a.y + y * a.x);
  }
  inline pnt operator + (const pnt& a) {
    return pnt(x + a.x, y + a.y);
  }
  inline void operator += (const pnt& a) {
    x += a.x, y += a.y;
  }
  inline void operator *= (const pnt& a) {
    ld x1 = x * a.x - y * a.y;
    y = x * a.y + y * a.x;    
    x = x1;
  }
  inline pnt operator - (const pnt& a) {
    return pnt(x - a.x, y - a.y);
  }
  inline pnt operator ! () {
    return pnt(x, -y);
  }
  inline pnt operator * (ld c) {
    return pnt(x * c, y * c);
  }
  inline pnt operator / (ld c) {
    return pnt(x / c, y / c);
  }
  inline void operator /= (ld c) {
    x /= c, y /= c;
  }
};
pnt a[maxn];
pnt c[maxn];
pnt pp[maxn];
int p[maxn];
inline void fft(int n, pnt *a, int dr) {
  if (n == 1) return;
  n /= 2;
  fft(n, a, dr);
  fft(n, a + n, dr);
  pnt w = pp[n];
  if (dr == -1)
    w = !w;
  pnt tk = pnt(1, 0);
  int i1 = n;
  for (int i = 0; i < n; i++, i1++){
    a[i1] *= tk;
    a[i] += a[i1];
    a[i1] = a[i] - a[i1] * 2;      
    tk *= w;
  }
}
inline void calcbit(int n) {
  int tk = 0;
  for (int i = 1; i < n; i++) {
    int ff = n >> 1;
    while (tk & ff)
      tk ^= ff, ff >>= 1;
    tk ^= ff;
    p[i] = tk;
  }
}
inline void revbit(int n, pnt *a) {
  for (int i = 0; i < n; i++) {
    if (p[i] > i)
      swap(a[i], a[p[i]]);
  }
}
inline void mul2(int n, pnt *a, pnt *c){
  fft(n, a, 1);
  a[n] = a[0]; 
  for (int i = 0; i < n; i++) {
    c[i] = ((a[i] + !a[n - i]) / 2) * ((a[i] - !a[n - i]) / 2) * pnt(0,-1);
  }
}
 
inline void mul(int* a0, int* b0, int n, int* c0) {
  for (int i = 0; i < n; i++) {
    a[p[i]].x = a0[i];
    a[p[i]].y = b0[i];
  }
  mul2(n, a, c);
  revbit(n, c);
  fft(n, c, -1);
  for (int i = 0; i < n; i++)
    c[i] /= n;
  for (int i = 0; i < n; i++){
    c0[i] = round(c[i].x);
  }
}

string s0 = "ACGT";
int sum[maxn];
int poly1[maxn];
int poly2[maxn];
int res[maxn];
int bad[maxn];
char s1[maxn];
char s2[maxn];
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  int n, m, k;
  scanf("%d %d %d\n", &n, &m, &k);

  for (int i=0;(1 << i) < maxn;i++){
    pp[1<<i]=pnt(cos(PI/(1<<i)),sin(PI/(1<<i)));
  }
  int cn=1;
  while (cn<n + m){
    cn*=2;
  }
  calcbit(cn);

  scanf("%s\n%s\n", s1, s2);
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < n; i++) {
      sum[i] = 0;
    }
    for (int i = 0; i < n; i++) if (s1[i] == s0[j]) {
      sum[max(0, i - k)]++;
      sum[min(n, i + k + 1)]--;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += sum[i];
      if (cur == 0) {
        poly1[i] = 1;
      } else {
        poly1[i] = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      if (s2[i] == s0[j]) {
        poly2[m - 1 - i] = 1;
      } else {
        poly2[m - 1 - i] = 0;
      }
    }
    mul(poly1, poly2, cn, res);
    for (int i = m - 1; i < n + m; i++) {
      if (res[i] > 0) {
        bad[i - (m - 1)] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; i++) if (bad[i] == 0) {
    ans++;
  }
  cout << ans << endl;
  cerr<<clock()*1./CLOCKS_PER_SEC<<endl;
  return 0;
}