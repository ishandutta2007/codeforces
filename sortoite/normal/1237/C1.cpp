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
typedef pair<pii, pii> pi4;

const int inf=0x3f3f3f3f,mod=1000000007;
const INT INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.),eps=1e-9;

inline int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 50050;

pi4 p[NN], q[NN];
int flag[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n, m;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
  	scanf("%d %d %d", &p[i].x.x, &p[i].x.y, &p[i].y.x);
  	p[i].y.y=i+1;
  }
  
  sort(p, p+n, [](const pi4& a, const pi4& b) {
		if(a.x.x == b.x.x) {
			if(a.x.y == b.x.y) return a.y.x<b.y.x;
			return a.x.y<b.x.y;
		}
		return a.x.x<b.x.x;
	});
	
  vector<pii> ans;
  for(int i=0, j; i<n; i=j) {
  	for(j=i; j<n && p[j].x == p[i].x; j++);
  	for(int k=i; k+1<j; k+=2) {
  		ans.pb({p[k].y.y, p[k+1].y.y});
  		p[k].y.y=p[k+1].y.y=0;
  	}
  }
  m=n;
  n=0;
  for(int i=0; i<m; i++) if(p[i].y.y) p[n++]=p[i];
  
	
  
  for(int i=0, j; i<n; i=j) {
  	for(j=i; j<n && p[j].x.x == p[i].x.x; j++);
  	for(int k=i; k+1<j; k+=2) {
  		ans.pb({p[k].y.y, p[k+1].y.y});
  		p[k].y.y=p[k+1].y.y=0;
  	}
  }
  
  m=n;
  n=0;
  for(int i=0; i<m; i++) if(p[i].y.y) p[n++]=p[i];
  
  for(int i=0; i<n; i+=2) {
  	ans.pb({p[i].y.y, p[i+1].y.y});
  }
  for(auto r:ans) printf("%d %d\n", r.x, r.y);
  return 0;
}