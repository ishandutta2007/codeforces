#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int N=100000,mod=1e9+7;

int tot,m,n,l,vis[100005],ans[450][100005];
int pw[100005],f[100005],g[100005];
char s[100005];

inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
inline int C(int x,int y){
	return (ll)f[x]*g[y]%mod*g[x-y]%mod;
}
inline int solve(int k){
	if(vis[k]) return vis[k];
	vis[k]=++tot;
	for(int i=k;i<=N;i++)
		ans[tot][i]=((ll)ans[tot][i-1]*26%mod+(ll)C(i-1,k-1)*pw[i-k]%mod)%mod;
	return vis[k];
}

int main(){
	pw[0]=1;f[0]=1;
	for(int i=1;i<=N;i++) pw[i]=(ll)pw[i-1]*25%mod;
	for(int i=1;i<=N;i++) f[i]=(ll)f[i-1]*i%mod;
	g[N]=exp(f[N],mod-2);g[0]=1;
	for(int i=N-1;i;i--) g[i]=(ll)g[i+1]*(i+1)%mod;
	for(int i=1;i<=N;i++) g[i]=(ll)g[i]*f[i-1]%mod;
	for(int i=1;i<=N;i++) g[i]=(ll)g[i-1]*g[i]%mod;
	scanf("%d",&m);
	scanf("%s",s+1);
	l=solve(strlen(s+1));
	for(int i=1;i<=m;i++){
		int typ;
		scanf("%d",&typ);
		if(typ==1) scanf("%s",s+1),l=solve(strlen(s+1));
		else scanf("%d",&n),printf("%d\n",ans[l][n]);
	}
	return 0;
}
/*
3
a
2 2
1 bc
2 5
*/