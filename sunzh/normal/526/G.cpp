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
#define ep emplace_back
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,q;
vector<PII>vec[100010];
int dis[100010];
void getdis(int s){
	memset(dis,-1,sizeof(dis));
	dis[s]=0;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(auto i:vec[u]){
			int v=i.fi;
			if(dis[v]==-1){
				dis[v]=dis[u]+i.se;
				Q.push(v);
			}
		}
	}
}
struct BIT{
	int t[100010];int cnt;
	void upd(int x,int k){
		while(x<=cnt){
			t[x]+=k;x+=x&-x;
		}
	}
	int qry(int x){
		if(x>cnt) x=cnt; 
		int res=0;
		while(x){
			res+=t[x];x-=x&-x;
		}
		return res;
	}
};
struct Tree{
	int fa[100010],son[100010],mxlen[100010];
	int top[100010];
	int dep[100010];
	int Fa[100010][22];
	struct lis{
		int top,down,len;
		bool operator <(const lis &x)const{
			return len>x.len;
		}
	}l[100010];
	int id[100010];
	int cnt=0;
	BIT T;
	void dfs1(int x,int f){
		fa[x]=f;Fa[x][0]=f;
		for(int i=1;i<=18;++i) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
		for(auto i:vec[x]){
			int v=i.fi;
			if(v==f) continue ;
			dep[v]=dep[x]+i.se;
			dfs1(v,x);
	//		printf("x:%d,v:%d,mx:%d\n",x,v,mxlen[v]+i.se);
			if(mxlen[v]+i.se>mxlen[x]) son[x]=v,mxlen[x]=mxlen[v]+i.se;
		}
	}
	void dfs2(int x,int topf){
		top[x]=topf;
		if(son[x]){
			dfs2(son[x],topf);
		}
		else{
			l[++cnt].top=topf;l[cnt].down=x;l[cnt].len=dep[x]-dep[fa[topf]];return ;
		}
		for(auto i:vec[x]){
			int v=i.fi;
			if(v==son[x]||v==fa[x]) continue ;
			dfs2(v,v);
		}
	}
	void solve(){
		sort(l+1,l+cnt+1);
		T.cnt=cnt;memset(T.t,0,sizeof(T.t));
		for(int i=1;i<=cnt;++i){
			id[l[i].top]=i;
//			printf("l[%d]:%d,%d,%d\n",i,l[i].top,l[i].down,l[i].len);
			T.upd(i,l[i].len);
		}
	}
	int getans(int x,int y){
		int tp=top[x];
		int anss=0;
		if(id[tp]<=2*y-1){
			anss=T.qry(2*y-1);
		}
		else{
			int fainl=x;
			for(int i=18;i>=0;--i){
				int X=Fa[fainl][i];
				if(id[top[X]]>2*y-1) fainl=Fa[fainl][i];
			}
			fainl=Fa[fainl][0];
			int ans=0;
//			if(id[top[fainl]]==2*y-1){
//				ans=T.qry(2*y-2)+dep[x]+mxlen[x];
////				printf("2:");
//			}
//			else{
				int Id=id[top[fainl]];
				int Down=l[Id].down;
				ans=max(T.qry(2*y-2)+dep[x]-dep[fainl]+mxlen[x],T.qry(2*y-1)-dep[Down]+dep[x]+mxlen[x]);
//				printf("3:");
//			}
			anss=ans;
		}
		return anss;
	}
}TS,Tt;
int main(){
	n=read(),q=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		vec[u].ep(v,w);vec[v].ep(u,w);
	}
	getdis(1);
	int S=0,TT=0;
	for(int i=1;i<=n;++i)if(dis[i]>dis[S]) S=i;
	getdis(S);
	for(int i=1;i<=n;++i) if(dis[i]>dis[TT])TT=i;
//	printf("%d %d\n",S,TT);
	TS.dfs1(S,0);
	TS.dfs2(S,S);
	TS.solve();
	Tt.dfs1(TT,0);
	Tt.dfs2(TT,TT);
	Tt.solve();
	int lastans=0;
	while(q--){
		int x=read(),y=read();
		x=((x+lastans-1)%n)+1;
		y=((y+lastans-1)%n)+1;
//		printf("x:%d,y:%d\n",x,y);
		printf("%d\n",lastans=max(TS.getans(x,y),Tt.getans(x,y)));
	}
	return 0;
}