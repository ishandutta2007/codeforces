#include <bits/stdc++.h>
#define x first
#define y second
#define pb emplace_back
#define sq(x) ((x)*(x))
using namespace std;
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;

const int inf=0x3f3f3f3f,mod=1000000007;
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

inline int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 2e5+10;

int a[NN];
pii p[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &p[i].x);
    p[i].y=i;
  }
  sort(p+1, p+n+1, [](pii a, pii b) { return a.x>b.x; });
  
  vector<pii> ans;
  for(int i=1; i<=n; i++) a[i]=p[i].y*2-1;
  for(int i=1; i<n; i++) ans.pb(p[i].y*2-1, p[i+1].y*2-1);
  
  for(int i=1, j; i<=n; i++) {
    j=i+p[i].x-1;
    if(a[j+1] == 0) {
      ans.pb(a[j], p[i].y*2);
      a[j+1]=p[i].y*2;
    }else {
      ans.pb(a[j], p[i].y*2);
    }
  }
  
  for(auto r:ans) printf("%d %d\n", r.x, r.y);
  return 0;
}