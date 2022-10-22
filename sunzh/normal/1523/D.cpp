#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<random>
#include<vector>
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
mt19937 rnd(998244353);
int n,m,p;
char g[200010][80];
int b[200010][80];
int cnt[80];
vector<int>vec[200010];
int idx[80],c;
int Cnt[80][80];
bool Ans[80];
int F[1<<15];
int main(){
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;++i) scanf("%s",g[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			b[i][j]=g[i][j]-'0';
			if(b[i][j]) ++cnt[j],vec[i].pb(j);
		}
	}
	for(int i=1;i<=m;++i){
		if(cnt[i]>=(n+1>>1)){
			idx[i]=++c;
		}
	}
	int ans=0;
	int Sta=0;
	for(int i=1;i<=40;++i){
		int x=rnd()%n+1;
		int sz=vec[x].size();
		memset(F,0,sizeof(F));
		for(int j=1;j<=n;++j){
			int S=0;
			for(int k=0;k<sz;++k){
				if(b[j][vec[x][k]]){
					S|=(1<<k);
				}
			}F[S]++;
		}
		for(int l=1;l<(1<<sz);l<<=1){
			for(int j=0;j<(1<<sz);j+=(l<<1)){
				for(int k=0;k<l;++k){
					F[j+k]+=F[j+k+l];
				}
			}
		}
		for(int S=1;S<(1<<sz);++S){
			if(F[S]>=(n+1>>1)&&__builtin_popcount(S)>ans){
				ans=__builtin_popcount(S);
				memset(Ans,0,sizeof(Ans));
				for(int j=0;j<sz;++j){
					if(S&(1<<j)) Ans[vec[x][j]]=1;
				}
			}
		}
	}
	mt19937 rnd2(time(0));
	for(int i=1;i<=45;++i){
		int x=rnd2()%n+1;
		int sz=vec[x].size();
		memset(F,0,sizeof(F));
		for(int j=1;j<=n;++j){
			int S=0;
			for(int k=0;k<sz;++k){
				if(b[j][vec[x][k]]){
					S|=(1<<k);
				}
			}F[S]++;
		}
		for(int l=1;l<(1<<sz);l<<=1){
			for(int j=0;j<(1<<sz);j+=(l<<1)){
				for(int k=0;k<l;++k){
					F[j+k]+=F[j+k+l];
				}
			}
		}
		for(int S=1;S<(1<<sz);++S){
			if(F[S]>=(n+1>>1)&&__builtin_popcount(S)>ans){
				ans=__builtin_popcount(S);
				memset(Ans,0,sizeof(Ans));
				for(int j=0;j<sz;++j){
					if(S&(1<<j)) Ans[vec[x][j]]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;++i) printf("%c",Ans[i]+'0');
}