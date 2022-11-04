#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using DO = double;
using LL = long long;
using VI = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
int power(int a, int b, int c=mod) {
  int ans=1;
  for(; b; b>>=1, a=(LL)a*a%c) {
    if(b&1) ans=(LL)ans*a%c;
  }
  return ans;
}
const int N = 5e5+10;
int mn[N][20];
int a[N];
int lc(int L, int R) {
  if(L == R) return L;
  int r=31-__builtin_clz(R-L+1);
  int t1=mn[L][r];
  int t2=mn[R-(1<<r)+1][r];
  if(a[t1]>a[t2]) {
    return t2;
  }else {
    return t1;
  }
}
map<pii, bool> mp;
LL pre(int L, int R) {
  if(L>R) {
    return -(0x3f3f3f3f3f3f3f3fll);
  }
  if(L == R) {
    return a[L];
  }
  int md = lc(L, R);
  LL vl=pre(L, md-1);
  LL vr=pre(md+1, R);
  if(vl+(LL)(R-md)*a[md]>vr+(LL)(md-L)*a[md]) {
    mp[{L, R}]=false;
    return vl+(LL)(R-md+1)*a[md];
  }else {
    mp[{L, R}]=true;
    return vr+(LL)(md-L+1)*a[md];
  }
}
int b[N];
void get(int L, int R) {
  if(L>R) return;
  if(L == R) {
    b[L]=a[L];
  }
  int md = lc(L, R);
  if(mp[{L, R}]) {
    for(int j=L; j<=md; j++) b[j]=a[md];
    get(md+1, R);
  }else {
    for(int j=md; j<=R; j++) b[j]=a[md];
    get(L, md-1);
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("C.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", a+i);
    mn[i][0]=i;
  }
  for(int j=1, t1, t2; j<20; j++) {
    for(int i=1; i<=n; i++) {
      t1=mn[i][j-1];
      t2=mn[min(n, i+(1<<j-1))][j-1];
      if(a[t1]>a[t2]) {
        mn[i][j]=t2;
      }else {
        mn[i][j]=t1;
      }
    }
  }
  pre(1, n);
  get(1, n);
  for(int i=1; i<=n; i++) {
    printf("%d ", b[i]);
  }
  puts("");
  return 0;
}