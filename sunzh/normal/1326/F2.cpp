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
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int ans[1<<18];
char str[20];
bool G[20][20];
int f[19][1<<18];
int g[19][1<<18];
int bitcnt[1<<18];
//int ans[1<<18];
std::map<std::vector<int>,std::vector<int> >Map; 
void dfs(int x,const std::vector<int>&l,const std::vector<int>&s){
	if(x==n){
		int res=0;
		for(int i=0;i<(1<<n);++i){
			(res+=((bitcnt[i^((1<<n)-1)]&1)?-1:1)*s[i]);
		}
		std::vector<int>p=Map[l];
		for(int i:p) ans[i]+=res;
		return ;
	}
	int lst=(l.empty()?0:l.back());
	for(int i=std::max(lst,1ll);i+x<=n;++i){
		if(i+x<n&&n-i-x<i) continue ;
		std::vector<int>sl(l),ss(s);
		sl.pb(i);
		for(int j=0;j<(1<<n);++j) ss[j]=ss[j]*g[i][j];
		dfs(x+i,sl,ss);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str+1);
		for(int j=1;j<=n;++j) G[i][j]=str[j]-'0';
	}
	for(int i=0;i<(1<<n);++i) bitcnt[i]=__builtin_popcount(i);
	for(int i=1;i<=n;++i) f[i][1<<i-1]=1;
	for(int i=0;i<(1<<n-1);++i){
		std::vector<int>p;
		int x=1;
		for(int j=0;j<n;++j){
			if(i&(1<<j)) ++x;
			else p.pb(x),x=1;
		}
		sort(p.begin(),p.end());
		Map[p].pb(i);
	}
	for(int i=1;i<(1<<n);++i)
		for(int j=1;j<=n;++j)
			if(f[j][i]){
				g[bitcnt[i]][i]+=f[j][i];
				for(int k=1;k<=n;++k) if(G[j][k]&&(!(i&(1<<k-1)))) f[k][i|(1<<k-1)]+=f[j][i];
			}
	for(int a=1;a<=n;++a){
		for(int i=0;i<n;++i){
			for(int S=0;S<(1<<n);++S){
				if((S>>i)&1) g[a][S]+=g[a][S^(1<<i)];
			}
		}
	}
	dfs(0,std::vector<int>(),std::vector<int>((1<<n),1));
	for(int i=0;i<n;++i){
		for(int S=0;S<(1<<n-1);++S){
			if((S>>i)&1) ans[S^(1<<i)]-=ans[S];
		}
	}
	for(int i=0;i<(1<<n-1);++i) printf("%lld ",ans[i]);
}