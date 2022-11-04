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
typedef pair<pii, int> pi3;

const int inf=0x3f3f3f3f,mod=1000000007;
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

inline int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 1e5+10;

int mx[NN][20];
int n;

int calc(int u, int d) {
	int ans=0;
	for(int i=0; i<20; i++) if(d&(1<<i)) {
		ans=max(ans, mx[u][i]);
		u+=(1<<i);
		u=((u-1)%n)+1;
	}
	return ans;
}

int lft[NN], rgt[NN];

void Lft(int u, int d) {
	for(; u>0; u-=u&-u) lft[u]=min(lft[u], d);
}

int calcL(int u, int ans=inf) {
	for(; u<NN; u+=u&-u) ans=min(ans, lft[u]);
	return ans;
}

void Rgt(int u, int d) {
	for(; u<NN; u+=u&-u) rgt[u]=min(rgt[u], d);
}

int calcR(int u, int ans=inf) {
	for(; u>0; u-=u&-u) ans=min(ans, rgt[u]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  memset(lft, 0x3f, sizeof lft);
  memset(rgt, 0x3f, sizeof rgt);
  
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &mx[i][0]);
  
  for(int j=1; j<20; j++) {
  	for(int i=1; i<=n; i++) {
  		mx[i][j]=max(mx[i][j-1], mx[((i+(1<<j-1)-1)%n)+1][j-1]);
  	}
  }
  for(int i=1; i<=n; i++) {
  	if(calc(i, n) <= 2*mx[i][0]) continue;
  	int st=n, ed=0, md;
  	while(st>1+ed) {
  		md=st+ed>>1;
  		int u=((i-md+n-1)%n)+1;
  		if(calc(u, md) > 2*mx[i][0]) st=md;
  		else ed=md;
  	}
  	int u=((i-st+n-1)%n)+1;
//  	cerr<<i<<' '<<u<<endl;
		Lft(u, st+1+ u);
		Rgt(u+1, st+n+ u+1);
  }
  for(int i=1; i<=n; i++) {
  	int d=min(calcL(i)-i, calcR(i)-i);
  	if(d>NN*2) printf("-1 ");
  	else printf("%d ", d-1);
  }
  return 0;
}