#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckyzc
#define y0 fuckcjb
#define x1 fuckjtjl
#define y1 fucksf
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
int n,m,k;
int ans[N];
set<int>g[N];
int q[N],l,r;
int x[N],y[N];
int cnt;bool in[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){
		scanf("%d%d",x+i,y+i);
		g[x[i]].insert(y[i]),g[y[i]].insert(x[i]);
	}
	l=r=0;cnt=n;
	rep(i,n)if((int)g[i].size()<k)q[++r]=i,in[i]=1;
	for(int tim=m;tim;--tim){
		while(l!=r){
			int c=q[++l];
			--cnt;
			for(auto v:g[c]){
				if(g[v].find(c)!=g[v].end()){
					g[v].erase(c);
					if((int)g[v].size()<k&&!in[v])
						q[++r]=v,in[v]=1;
				}
			}
		}
		ans[tim]=cnt;
		if(g[x[tim]].find(y[tim])!=g[x[tim]].end()){
			g[x[tim]].erase(y[tim]);
			if((int)g[x[tim]].size()<k&&!in[x[tim]])
				q[++r]=x[tim],in[x[tim]]=1;
		}
		if(g[y[tim]].find(x[tim])!=g[y[tim]].end()){
			g[y[tim]].erase(x[tim]);
			if((int)g[y[tim]].size()<k&&!in[y[tim]])
				q[++r]=y[tim],in[y[tim]]=1;
		}
	}
	rep(i,m)printf("%d\n",ans[i]);
	return 0;
}