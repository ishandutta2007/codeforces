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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int X;
int a[150010];
int sz[4500010];
int tr[4500010][2];
int cnt=1;
int pw[150010];
const int mod=998244353;
void insert(int x){
	int nw=1;
	for(int i=29;i>=0;--i){
		int t=(x>>i&1);
		if(!tr[nw][t]) tr[nw][t]=++cnt;
		nw=tr[nw][t];
		++sz[nw];
	}
}
int dfs(int x,int y,int dep){
	if(!x) return pw[sz[y]];
	if(!y) return pw[sz[x]];
	if(dep==-1) return pw[(x==y?sz[x]:sz[x]+sz[y])];
	int t=X>>dep&1;
	if(t){
		if(x==y) return dfs(tr[x][0],tr[x][1],dep-1);
		else return 1ll*dfs(tr[x][0],tr[y][1],dep-1)*dfs(tr[x][1],tr[y][0],dep-1)%mod;
	}
	else{
		int res=(dfs(tr[x][0],tr[y][0],dep-1)+dfs(tr[x][1],tr[y][1],dep-1)-1)%mod;
		if(x==y) return res;
		(res+=1ll*(pw[sz[tr[x][0]]]-1)*(pw[sz[tr[x][1]]]-1)%mod)%=mod;
		(res+=1ll*(pw[sz[tr[y][0]]]-1)*(pw[sz[tr[y][1]]]-1)%mod)%=mod;
		return res;
	}
}
int main(){
	n=read(),X=read();
	pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;++i){
		a[i]=read();insert(a[i]);
	}sz[1]=n;
	printf("%d\n",(dfs(1,1,29)-1+mod)%mod);
}