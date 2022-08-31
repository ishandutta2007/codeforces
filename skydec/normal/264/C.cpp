#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
#define INF (LL)1e16
int n,q,a,b;
LL dp[MAXN];int v[MAXN],c[MAXN];
struct jdb{
	int max1,max2;
	LL get(int x){
		if(max1==-1)return -INF;
		else if(max1!=x)return dp[max1];
		else if(max2==-1)return -INF;
		else return dp[max2];
	}
	void renew(int x){
		if(max1==-1)max1=x;
		else if(x==max1)return;
		else if(dp[x]>dp[max1]){max2=max1;max1=x;}
		else if(max2==-1)max2=x;
		else if(dp[x]>dp[max2])max2=x;
	}
}JDB;
void init(){
	JDB.max1=JDB.max2=-1;
	rep(i,1,n)dp[i]=-INF;
}
void work(){
	dp[c[1]]=v[1]*1ll*b;
	JDB.renew(c[1]);
	rep(i,2,n){
		LL tmp=JDB.get(c[i])+b*1ll*v[i];
		LL tmp2=dp[c[i]]+a*1ll*v[i];
		tmp=max(tmp,tmp2);
		tmp2=b*1ll*v[i];
		tmp=max(tmp,tmp2);
		if(tmp>dp[c[i]]){
		dp[c[i]]=tmp;
		JDB.renew(c[i]);
		}
	}
	LL ans=0;
	rep(i,1,n)ans=max(ans,dp[i]);
	printf("%I64d\n",ans);
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n)scanf("%d",&v[i]);
	rep(i,1,n)scanf("%d",&c[i]);
	while(q--){
		init();
		scanf("%d%d",&a,&b);
		work();
	}
	return 0;
}