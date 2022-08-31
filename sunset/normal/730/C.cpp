#include<bits/stdc++.h>
#define maxn 6011
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1];
struct shop{
	int c,k,p;
	shop(){}
	shop(int c,int k,int p):c(c),k(k),p(p){}
	int operator<(const shop& s)const{
		return p<s.p;
	}
}ss[maxn];
int dist[maxn],q[maxn<<1],ql,qr,n,m,w,head[maxn],esz;
int bfs(int bg){
	ql=qr=0;
	q[qr++]=bg;
	memset(dist,0,sizeof(dist));
	dist[bg]=1;
	int wx=1;
	while(ql<qr){
		int t=q[ql++];
		for(int x=head[t];x;x=e[x].nxt)if(!dist[e[x].r])
			q[qr++]=e[x].r,dist[e[x].r]=dist[t]+1,wx=max(wx,dist[e[x].r]);
	}
	return wx;
}
void addedge(int u,int v){
	e[++esz].nxt=head[u];e[esz].r=v;head[u]=esz;
}
bool check(int ans,long long r,long long a){
	for(int i=1;i<=w;++i)if(dist[ss[i].c]&&dist[ss[i].c]<=ans){
		if(r<ss[i].k){
			a-=1ll*ss[i].p*r,r=0;
		} else a-=1ll*ss[i].p*ss[i].k,r-=ss[i].k;
		if(a<0) return false;
		if(r==0)return true;
	}
	if(r>0)return false;
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),addedge(u,v),addedge(v,u);
	scanf("%d",&w);
	for(int i=1;i<=w;++i){
		int c,k,p;
		scanf("%d%d%d",&c,&k,&p);
		ss[i]=shop(c,k,p);
	}
	int q;scanf("%d",&q);
	sort(ss+1,ss+w+1);
	for(int i=1;i<=q;++i){
		int x,y,a;scanf("%d%d%d",&x,&y,&a);
		int r=bfs(x),l=1;
		while(l<r){
			int ans=(l+r)>>1;
			if(check(ans,y,a))r=ans;
			else l=ans+1;
		}
		if(check(l,y,a))printf("%d\n",l-1);
		else printf("-1\n");
	}
}