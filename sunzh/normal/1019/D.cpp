#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define int long long
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,S;
PII a[2010];
struct nd{
	PII x;
	int u,v;
	bool operator <(const nd &r)const{
		return x.fi*r.x.se-x.se*r.x.fi>0;
	}
}e[2000010];
int cnt;
PII operator -(PII x,PII y){
	return mp(x.fi-y.fi,x.se-y.se);
}
int operator *(PII x,PII y){
	return x.fi*y.se-x.se*y.fi;
}
int pos[2010],rk[2010];
void confirm(int i,int j,int k){
	printf("Yes\n");
	printf("%d %d\n",a[i].fi,a[i].se);
	printf("%d %d\n",a[j].fi,a[j].se);
	printf("%d %d\n",a[k].fi,a[k].se);
	return ;
}
signed main(){
	n=read(),S=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1);
	// for(int i=1;i<=n;++i) printf("%d %d\n",a[i].fi,a[i].se);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			e[++cnt].x=a[j]-a[i];
			e[cnt].u=i,e[cnt].v=j;
		}
	}S<<=1;
	sort(e+1,e+cnt+1);
	// for(int i=1;i<=cnt;++i) printf("%d %d\n",e[i].x.fi,e[i].x.se);
	for(int i=1;i<=n;++i) pos[i]=rk[i]=i;
	for(int i=1;i<=cnt;++i){
		int u=e[i].u,v=e[i].v;
		if(rk[u]>rk[v]) swap(u,v);
		// printf("u:%d,v:%d\n",u,v);
		// for(int j=1;j<=n;++j) printf("%d ",pos[j]);printf("\n");
		int l=1,r=rk[u],res=-1;
		while(l<=r){
			int mid=l+r>>1;
			int s=abs((a[pos[mid]]-a[u])*(a[v]-a[u]));
			// printf("mid:%d,%d,%d\n",mid,pos[mid],s);
			if(s==S){
				confirm(u,v,pos[mid]);return 0;
			}
			if(s<S) r=mid-1;else l=mid+1;
		}
		swap(rk[u],rk[v]);swap(pos[rk[u]],pos[rk[v]]);
	}
	printf("No\n");
}