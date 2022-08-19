#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#include<sys/time.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int p[MX];
P a[MX], b[MX];

void up(int v){
	while(v){
		int u = p[v], x = max(a[v].fi,b[v].fi+1);
		bool nx = false;
		if(a[u].se == v){
			if(a[u].fi < x) a[u].fi = x, nx = true;
		} else if(b[u].se == v){
			if(b[u].fi < x) b[u].fi = x, nx = true;
		} else if(b[u].fi < x) b[u] = P(x,v), nx = true;
		if(b[u].fi > a[u].fi) swap(a[u],b[u]);
		if(!nx) break;
		v = u;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	rrep(i,n){
		scanf("%d",&p[i]);
		p[i]--;
		up(i);
		/*
		rep(j,n)printf("%d ",a[j].fi); puts("");
		rep(j,n)printf("%d ",b[j].fi); puts("\n");
		//*/printf("%d%c",a[0].fi,i==n?'\n':' ');
	}
	
	return 0;
}