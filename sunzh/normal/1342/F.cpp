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
int T;
int n;
int a[21];
int val[1<<15];
PII dp[16][16][1<<15];
int pr[16][16][1<<15];
int num[16];
vector<PII>Ans;
void print(int i,int j,int k){
	if(i==0) return ;
	j=dp[i][j][k].se;
	int t=pr[i][j][k];
	for(int p=1;p<=n;++p) if(t>>(p-1)&1){
		if(p!=j) Ans.pb(mp(p,j));
	}
	print(i-1,j-1,k^t);
}
int main(){
	T=read();memset(dp,0x3f,sizeof(dp));
	for(int o=1;o<=T;++o){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		// if(o==37){
		// 	printf("%d\n",n);
		// 	for(int i=1;i<=n;++i) printf("%d ",a[i]);
		// }
		for(int i=0;i<(1<<n);++i){
			val[i]=0;
			for(int j=1;j<=n;++j) if(i>>(j-1)&1) val[i]+=a[j];
		}
		for(int i=0;i<=n;++i) dp[0][i][0]=mp(0,0);
		PII ans=mp(0x3f3f3f3f,0x3f3f3f3f);
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				for(int k=0;k<(1<<n);++k){
					dp[i][j][k]=dp[i][j-1][k];
					if(k>>(j-1)&1){
						for(int l=k;l;l=(l-1)&k) if(l>>(j-1)&1){
							if(val[l]>dp[i-1][j-1][k^l].fi){
								if(val[l]<dp[i][j][k].fi){
									dp[i][j][k].fi=val[l];dp[i][j][k].se=j;pr[i][j][k]=l;
								}
							}
						}
					}
				}
				if(dp[i][j][(1<<n)-1].fi<val[(1<<n)-1]+120){
					ans=min(ans,mp(n-i,j));
				}
			}
		}
		Ans.clear();
		for(int i=1;i<=n;++i) num[i]=i;
		printf("%d\n",ans.fi);
		print(n-ans.fi,ans.se,(1<<n)-1);
		for(PII i:Ans){
			printf("%d %d\n",num[i.fi],num[i.se]);
			for(int l=i.fi;l<=n;++l) --num[l];
		}
		for(int i=0;i<=n;++i) for(int j=i;j<=n;++j) for(int k=0;k<(1<<n);++k) dp[i][j][k].fi=0x3f3f3f3f;
	}
}