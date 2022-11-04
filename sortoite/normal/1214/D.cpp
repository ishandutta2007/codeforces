#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define sq(x) ((x)*(x))
using namespace std;
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef pair<pii, int> pi3;

const int inf=0x3f3f3f3f;
const pii mod={1000000007, 998244353}, zero={0, 0};
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

void add(pii&a, pii b){
  a.x+=b.x; if(a.x>=mod.x) a.x-=mod.x;
  a.y+=b.y; if(a.y>=mod.y) a.y-=mod.y;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n, m;
  vector<string> s;
  scanf("%d %d", &n, &m);
  s.resize(n);
  for(int i=0; i<n; i++) cin>>s[i];
  vector<VP> d(n, VP(m)), e(n, VP(m));
  
  d[0][0]={1, 1};
  for(int i=0; i<n; i++) {
    for(int j=(0==i); j<m; j++) if(s[i][j]=='.') {
      d[i][j]=zero;
      if(i && s[i-1][j]=='.') add(d[i][j], d[i-1][j]);
      if(j && s[i][j-1]=='.') add(d[i][j], d[i][j-1]);
    }
  }
  
  e[n-1][m-1]={1, 1};
  for(int i=n-1; i>=0; i--) {
    for(int j=m-1-(n-1==i); j>=0; j--) if(s[i][j]=='.') {
      e[i][j]=zero;
      if(i+1<n && s[i+1][j]=='.') add(e[i][j], e[i+1][j]);
      if(j+1<m && s[i][j+1]=='.') add(e[i][j], e[i][j+1]);
    }
  }
  
  if(e[0][0] == zero) return puts("0"), 0;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(i+j>0 && i+j<n+m-2 && s[i][j] == '.') {
        if(e[0][0].x == (INT)d[i][j].x*e[i][j].x%mod.x && 
          e[0][0].y == (INT)d[i][j].y*e[i][j].y%mod.y) return puts("1"), 0;
      }
    }
  }
  
  puts("2");
  return 0;
}