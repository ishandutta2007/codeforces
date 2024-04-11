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
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
vector<int>vec[110];
struct bitst{
	long long x,y;
	int highest_bit(){
		if(x){
			for(int i=60;i>=0;--i){
				if(x&(1ll<<i)){
					return i+61;
				}
			}
		}
		else for(int i=60;i>=0;--i) if(y&(1ll<<i)) return i;
		return -1;
	}
	void set1(int i){
		if(i>=61){
			x|=(1ll<<(i-61));
		}
		else y|=(1ll<<i);
	}
	void rev(int i){
		if(i>=61) x^=(1ll<<(i-61));
		else y^=(1ll<<i);
	}
	bool have(int i){
		if(i>=61) return (x>>(i-61))&1;
		else return (y>>i)&1; 
	} 
}f[110];
bool operator <(const bitst &x,const bitst &y){
	return x.x<y.x?true:(x.x==y.x&&x.y<y.y);
}
bool operator >(const bitst &x,const bitst &y){
	return x.x>y.x?true:(x.x==y.x&&x.y>y.y);
}
map<PII,int>e;
bool vis[110];
bool chk(bitst x,vector<int>tmp){
	priority_queue<bitst >Q;
	for(int i:tmp) Q.push(f[i]);
	for(int i=n-1;i>=0;--i){
		if(x.have(i)&&Q.size()){
			bitst now=Q.top();
			Q.pop();
			if(now.highest_bit()>i) return 0;
			if(now.highest_bit()==i){
				now.rev(i);Q.push(now);
			}
		}
	}
	return Q.empty();
}
void getval(int x,bitst y,vector<int>tmp){
	priority_queue<pair<bitst,int> >Q;
	for(int i:tmp) Q.push(mp(f[i],i));
	for(int i=n-1;i>=0;--i){
		if(y.have(i)&&Q.size()){
			bitst now=Q.top().fi;
			int u=Q.top().se;
			Q.pop();
			if(now.highest_bit()==i){
				now.rev(i);Q.push(mp(now,u));
			}
			else{
				e[mp(x,u)]=e[mp(u,x)]=i;
//				printf("e[%d,%d]=%d\n",x,u,i);
			}
		}
	}
}
void dfs1(int x,int fa){
//	printf("%d %d\n",x,fa);
	vector<int>sons;
	for(int v:vec[x]){
		if(v==fa) continue ;
		dfs1(v,x);
		sons.pb(v);
	}
	for(int i=n-1;i>=0;--i){
		f[x].set1(i);
	}
	for(int i=n-1;i>=0;--i){
		f[x].rev(i);
		if(!chk(f[x],sons)) f[x].rev(i);
	}
	getval(x,f[x],sons);
//	printf("f[%d]=%d\n",x,f[x].y);
//	printf("retu");
}
PII maxn;
void dfs2(int x,int fa){
	for(int v:vec[x]){
		if(vis[v]||v==fa) continue ;
		if(e[mp(x,v)]>e[maxn]) maxn=mp(x,v);
		dfs2(v,x);
	}
}
int solve(int x){
	maxn=mp(-1,-1);
	e[maxn]=-1;
	dfs2(x,0);
	if(maxn.fi==-1) return x;
	printf("? %d %d\n",maxn.fi,maxn.se);fflush(stdout);
	int y=read();
	if(y==maxn.fi) vis[maxn.se]=1;
	else vis[maxn.fi]=1;
	return solve(y);
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	int x=solve(1);
	printf("! %d\n",x);fflush(stdout);return 0;
}