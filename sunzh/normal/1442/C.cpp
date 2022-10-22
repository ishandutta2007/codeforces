#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
vector<PII> vec[400010];
int dis[400010][22];
int dfn[400010];
int step[400010];
struct node{
	int x,y;int dis;
	bool operator <(const node &p)const{
		return dis<p.dis;
	}
	bool operator >(const node &p)const{
		return dis>p.dis;
	}
};
void dij(){
	memset(step,0x3f,sizeof(step));
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(mp(0,1));
	step[1]=0;
	while(!Q.empty()){
		PII u=Q.top();Q.pop();
		if(u.fi!=step[u.se]) continue ;
		for(auto i:vec[u.se]){
			PII v;v.se=i.fi;v.fi=u.fi+i.se;
			if(v.fi<step[v.se]){
				step[v.se]=v.fi;
				Q.push(v);
			}
		}
	}
}
void dijk(){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<node,vector<node>,greater<node> >Q;
	node s={1,0,0};
	dis[1][0]=0;
	Q.push(s);
	while(!Q.empty()){
		node u=Q.top();Q.pop();
		if(dis[u.x][u.y]!=u.dis) continue ;
		if(u.y==18) continue ;
		for(auto i:vec[u.x]){
			node v;
			v.x=i.fi,v.y=u.y+i.se,v.dis=u.dis+1;
			if(dis[v.x][v.y]>v.dis){
				dis[v.x][v.y]=v.dis;Q.push(v);
			}
		}
	}
}
void bfs(int s){
	queue<PII>Q;
	Q.push(mp(s,1));
	dfn[s]=1;
	while(!Q.empty()){
		PII u=Q.front();Q.pop();
//		printf("u:%d\n",u);
		for(auto i:vec[u.fi]){
			PII v;v.fi=i.fi;
			if(dfn[v.fi]) continue ;
			if(step[v.fi]==step[u.fi]+i.se){
				v.se=u.se+1;dfn[v.fi]=dfn[u.fi]+1;Q.push(v);
			}
		}
	}
}
const int mod=998244353;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		vec[u].ep(v,0);
		vec[v].ep(u+n,1);
		vec[v+n].ep(u+n,0);vec[u+n].ep(v,1);
	}
	dij();
	if(min(step[n],step[n+n])<=ceil(log2(m))){
		dijk();
		int ans=0x3f3f3f3f;
		for(int i=0;i<=18;++i){
			ans=min(ans,((1<<i)-1+min(dis[n][i],dis[n+n][i]))%mod);
		}
		print(ans);
	}
	else if(step[n]<step[n+n]){
		bfs(1);
		printf("%lld\n",(1ll*(qpow(2,step[n])-1+mod)%mod+dfn[n]-1)%mod);
//		printf("%d\n",qpow(2,step[n]));printf("%d %d\n",dfn[1],dfn[n+1]);
	}
	else{
		bfs(1);
		printf("%lld\n",(1ll*(qpow(2,step[n+n])-1+mod)%mod+dfn[n+n]-1)%mod);
	}
//	printf("step3:%d\n",step[3]);
}