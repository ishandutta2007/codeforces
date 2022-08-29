#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=10005;
int a[N],b[N];
int t[N];
int ma,mb;
int _n;
bitset<N>f[2];
int w=0;
int L,R;
int dp[2][N][2];
int main(){
	scanf("%d%d%d",&_n,&L,&R);
	rep(i,1,_n){
		scanf("%d",&t[i]);
		w+=t[i];
	}
	R=min(R,w);
	w++;
	rep(i,1,_n){
		int x;scanf("%d",&x);
		if(x==0)a[++ma]=t[i];
		else b[++mb]=t[i];
	}
	int now=0;
	f[now][0]=1;
	rep(i,1,ma){
		f[now^1]=f[now]|(f[now]<<a[i]);
		now^=1;
	}
	sort(b+1,b+1+mb);
	rep(i,0,w){
		if(f[now][i]){
			dp[now][i][0]=0;
		}
		else dp[now][i][0]=-1000000000;
		dp[now][i][1]=-1000000000;
	}
	per(i,mb,1){
		rep(j,0,w)rep(k,0,1)dp[now^1][j][k]=-1000000000;

		rep(j,0,w)rep(k,0,1)if(dp[now][j][k]>=0){
			int w=dp[now][j][k];
			dp[now^1][j][1]=max(dp[now^1][j][1],w);
			dp[now^1][min(j+b[i],R+1)][k]=max(dp[now^1][min(j+b[i],R+1)][k],w+(j>=L&&j<=R));
		}
		now^=1;
	}
	int ans=0;
	rep(i,0,w)rep(k,0,1){
		ans=max(ans,dp[now][i][k]+(k&&(i<=R&&i>=L)));
	}
	printf("%d\n",ans);
	return 0;
}