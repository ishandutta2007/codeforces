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
#define jsb 1000000007
#define MAXN 110000
int sum[MAXN];int n;
vector<int>a[MAXN];
int N=100000;
int Pow(int x,int y){
	int z=1;
	for(;y;y>>=1,x=x*1ll*x%jsb)if(y&1)z=z*1ll*x%jsb;
	return z;
}
int calc(int sl,int fat){
	return (Pow(fat,sl)-Pow(fat-1,sl))%jsb;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int v;scanf("%d",&v);sum[v]++;
	}
	rep(i,1,N)sum[i]+=sum[i-1];
	rep(i,1,N)rep(j,1,N/i)a[i*j].pb(i);
	int ans=0;
	rep(i,1,N){
		int u=sum[N]-sum[i-1];
		if(!u)continue;
		int res=calc(u,a[i].size());
		for(int j=0;j+1<a[i].size();j++){
			res=res*1ll*Pow(j+1,sum[a[i][j+1]-1]-sum[a[i][j]-1])%jsb;
		}
		ans=(ans+res)%jsb;
		//printf("%d %d\n",i,ans);
	}
	printf("%d\n",(ans+jsb)%jsb);
	return 0;
}