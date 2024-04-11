#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
vector<int>vec[300010];
int f[300010][3];
const int mod=998244353;
void dfs(int x,int fa){
	f[x][0]=1;
	for(auto v:vec[x]){
		if(v==fa) continue ;
		dfs(v,x);
		f[x][2]=(1ll*(f[x][0]+f[x][2])*((2ll*f[v][0]%mod+f[v][1]+f[v][2])%mod)%mod+1ll*f[x][2]*((f[v][0]+f[v][1]+f[v][2])%mod)%mod)%mod;
//		(f[x][2]+=1ll*f[x])%=mod;
		f[x][1]=(1ll*(f[x][1]+f[x][0])*(f[v][0]+f[v][2])%mod+1ll*f[x][1]*((f[v][0]+f[v][1]+f[v][2])%mod)%mod)%mod;
		f[x][0]=1ll*f[x][0]*((f[v][0]+f[v][1]+f[v][2])%mod)%mod;
	}
}
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	print((f[1][0]+f[1][1]+f[1][2]-1+mod)%mod);
	return 0;
}