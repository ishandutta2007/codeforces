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
#define se second
#define pb push_back
#define ep emplace_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int a[3000010],b[3000010];
int pos[6000010];
vector<PII>vec[2000010];
int P[2000010];
int PP;
void build(int p,int l,int r){
	PP=max(PP,p);
	// printf("p:%d,l:%d,r:%d\n",p,l,r);
	if(l==r){
		P[p]=l;
		pos[l]=p;return ;
	}
	int mid=l+r>>1;
	vec[p].ep(p<<1,0);vec[p].ep(p<<1|1,0);
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void con(int x,int p,int l,int r,int L,int R){
	if(L>R) return ;
	// printf("L:%d,R:%d\n",L,R);
	if(l>=L&&r<=R){
		vec[x].ep(p,1);return ;
	}
	int mid=l+r>>1;
	if(L<=mid) con(x,p<<1,l,mid,L,R);
	if(R>mid) con(x,p<<1|1,mid+1,r,L,R);
}
int dis[2000010],pre[2000010];
void dij(int s){
	priority_queue<PII,vector<PII> ,greater<PII> >Q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	Q.push(mp(0,s));
	while(!Q.empty()){
		PII nw=Q.top();Q.pop();
		if(nw.fi!=dis[nw.se]) continue ;
		int u=nw.se;
		for(PII i:vec[nw.se]){
			int v=i.fi;
			// printf("u:%d,v:%d\n",u,v);
			if(dis[v]>dis[u]+i.se){
				dis[v]=dis[u]+i.se;
				pre[v]=u;
				Q.push(mp(dis[v],v));
			}
		}
	}
}
int main(){
	memset(P,-1,sizeof(P));
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	build(1,0,n);
	// printf("%d\n",PP);
	for(int i=0;i<=n;++i) vec[pos[i]].ep(PP+i+b[i]+1,0);
	for(int i=1;i<=n;++i) con(PP+i+1,1,0,n,i-a[i],i);
	dij(PP+n+1);
	if(dis[PP+1]>1e8){
		printf("-1\n");return 0;
	}
	int nw=PP+1;
	vector<int>ans;
	// printf("%d\n")
	while(nw!=PP+n+1){
		// printf("nw:%d\n",nw);
		if(P[nw]!=-1) ans.pb(P[nw]);
		nw=pre[nw];
	}
	printf("%d\n",ans.size());
	reverse(ans.begin(),ans.end());
	for(int i:ans) printf("%d ",i);
}