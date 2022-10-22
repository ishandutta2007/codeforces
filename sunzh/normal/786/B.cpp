#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
#define ep emplace_back 
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,q,s;
int cnt;
struct node{
	int ls,rs;
}tre[800010];
vector<PII>vec[800010];
int rtin,rtout;
void buildIn(int &p,int l,int r){
	if(l==r){
		p=l;return ;
	}
	p=++cnt;
	int mid=l+r>>1;
	buildIn(tre[p].ls,l,mid);buildIn(tre[p].rs,mid+1,r);
	vec[p].ep(tre[p].ls,0);vec[p].ep(tre[p].rs,0);
}
void buildOut(int &p,int l,int r){
	if(l==r){
		p=l;return ;
	}
	p=++cnt;
	int mid=l+r>>1;
	buildOut(tre[p].ls,l,mid);buildOut(tre[p].rs,mid+1,r);
	vec[tre[p].ls].ep(p,0);vec[tre[p].rs].ep(p,0);
}

void updin(int p,int l,int r,int L,int R,int fr,int w){
	if(l>=L&&r<=R){
//		printf("p:%d,fr:%d\n",p,fr);
		vec[fr].ep(p,w);return ;
	}
	int mid=l+r>>1;
	if(L<=mid) updin(tre[p].ls,l,mid,L,R,fr,w);
	if(R>mid) updin(tre[p].rs,mid+1,r,L,R,fr,w);
}
void updout(int p,int l,int r,int L,int R,int ed,int w){
	if(l>=L&&r<=R){
		vec[p].ep(ed,w);return ;
	}
	int mid=l+r>>1;
	if(L<=mid) updout(tre[p].ls,l,mid,L,R,ed,w);
	if(R>mid) updout(tre[p].rs,mid+1,r,L,R,ed,w);
}
int dis[800010];
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(mp(0,s));
	while(!Q.empty()){
		PII now=Q.top();Q.pop();
		if(now.fi!=dis[now.se]) continue ;
		for(auto i:vec[now.se]){
			int v=i.fi;
			int d=i.se+now.fi;
			if(dis[v]>d){
				dis[v]=d;Q.push(mp(d,v));
			}
		}
	}
}
signed main(){
	n=read(),q=read(),s=read();
	cnt=n;
	buildIn(rtin,1,n);
	buildOut(rtout,1,n);
	for(int i=1;i<=q;++i){
		int op=read();
		if(op==1){
			int u=read(),v=read(),w=read();
			vec[u].ep(v,w);
		}
		else if(op==2){
			int v=read(),l=read(),r=read(),w=read();
			updin(rtin,1,n,l,r,v,w);
		}
		else{
			int v=read(),l=read(),r=read(),w=read();
			updout(rtout,1,n,l,r,v,w);
		}
	}
	dijkstra(s);
	for(int i=1;i<=n;++i) printf("%lld ",dis[i]>=1e15?-1:dis[i]);
	return 0;
}