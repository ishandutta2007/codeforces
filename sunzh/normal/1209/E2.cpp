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
int T;
int n,m;
int a[20][2010];
struct node{
	int x,id;
	bool operator <(const node &y)const{
		return x>y.x;
	}
}Maxn[2010];
int p[20];
int dp[1<<13];
int t[1<<13];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;++i) Maxn[i].x=Maxn[i].id=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();Maxn[j].x=max(Maxn[j].x,a[i][j]);Maxn[j].id=j;
			}
		}
		sort(Maxn+1,Maxn+m+1);
		for(int i=1;i<=m;++i) p[i]=Maxn[i].id;
		int ans=0;
		for(int i=1;i<(1<<n);++i) dp[i]=0;
		for(int i=1;i<=min(n,m);++i){
			for(int j=0;j<(1<<n);++j){
				t[j]=0;
			}
			for(int j=1;j<(1<<n);++j){
				for(int k=1;k<=n;++k){
					if((1<<k-1)&j){
						t[j]+=a[k][p[i]];
					}
				}
			}
			for(int j=1;j<(1<<n);++j){
				for(int k=1;k<n;++k){
					int tmp=(j>>k)|((j&((1<<k)-1))<<(n-k));
//					printf("j:%d,k:%d,tmp:%d\n",j,k,tmp);
					t[j]=max(t[j],t[tmp]);
				}
			}
			for(int j=(1<<n)-1;j;--j){
				for(int S=j;S;S=(S-1)&j){
					dp[j]=max(dp[j],dp[j^S]+t[S]);
				}
			} 
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
}