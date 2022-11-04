#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
inline void smax(int& a, const int& b) {
  if(a<b) a=b;
}
using VI = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int N = 2e5+10, M = 1<<8;
VI v[N];
int dp[N][M];
int mx[M];
int ca[M];
int to[8];
void update(int* d, int* p, const VI& a, const VI& b, int t) {
  int la=a.size(), lb=b.size();
  int A=0, B=0;
  for(int i=0; i<la; i++) {
    for(int j=0; j<lb; j++) {
      if(a[i] == b[j]) {
        A|=(1<<i);
        B|=(1<<j);
        to[j]=i;
      }
    }
  }
  int re=((1<<la)-1)^A;
  memset(ca, 0, sizeof ca);
  for(int i=A; ; i=(i-1&A)) {
    for(int j=re; ; j=(j-1)&re) {
      smax(ca[i], d[i|j]);
      if(j == 0) {
        break;
      }
    }
    if(i == 0) {
      break;
    }
  }
  re=((1<<lb)-1)^B;
//  cerr<<re<<endl;
  for(int i=B; ; i=(i-1&B)) {
    int f=0;
    for(int j=0; j<lb; j++) {
      if(i&(1<<j)) {
        f|=(1<<to[j]);
      }
    }
    for(int j=re; ; j=(j-1)&re) {
      smax(p[i|j], ca[f]+((__builtin_popcount(i|j)&1)?t:0));
//      cerr<<i<<' '<<j<<' '<<p[i|j]<<' '<<f<<endl;
      if(j == 0) {
        break;
      }
    }
    if(i == 0) {
      break;
    }
  }
//  exit(0);
}
pii p[N];
int x[N];
int main() {
#ifndef ONLINE_JUDGE
  freopen("E.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n, m, k, xn;
  scanf("%d %d %d", &n, &m, &k);
  for(int i=1, L, R; i<=n; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
    x[xn++]=p[i].x;
    x[xn++]=p[i].y+1;
  }
  sort(x, x+xn);
  xn=unique(x, x+xn)-x;
  for(int i=1; i<=n; i++) {
    p[i].x=lower_bound(x, x+xn, p[i].x)-x;
    p[i].y=lower_bound(x, x+xn, p[i].y+1)-x;
    for(int j=p[i].x+1; j<=p[i].y; j++) {
      v[j].pb(i);
    }
  }
  int t = v[1].size();
  for(int b=0; b<(1<<t); b++) {
    int f=0;
    for(int i=0; i<t; i++) {
      if(b&(1<<i)) {
        f^=1;
      }
    }
    if(f) {
      dp[1][b]=x[1]-x[0];
    }
  }
  for(int i=2; i<xn; i++) {
    update(dp[i-1], dp[i], v[i-1], v[i], x[i]-x[i-1]);
  }
//  for(int i=1; i<xn; i++) {
//    for(int j=0; j<(1<<v[i].size()); j++) {
//      for(int f=0; f<v[i].size(); f++) {
//        if(j&(1<<f)) cout<<1;
//        else cout<<0;
//      }
//      cout<<' '<<dp[i][j]<<endl;
//    }
//    cout<<endl;
//  }exit(0);
  
  int ans=0;
  t=v[xn-1].size();
  for(int b=0; b<(1<<t); b++) {
    ans=max(dp[xn-1][b], ans);
  }
  cout<<ans<<endl;
  return 0;
}