#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define jsb 1000000007
using namespace std;
#define MAXN 1100000
int n,m,k;int is[MAXN];int tw[MAXN];
int Pow(int a,int b)
{
	return tw[b];
}
int tt=0;
int sum[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&k);tw[0]=1;rep(i,1,n)tw[i]=tw[i-1]*2ll%jsb;
	rep(i,1,m)
	{
		int a,b;scanf("%d%d",&a,&b);
		if(b-a!=1&&b-a!=k+1){printf("0\n");return 0;}
		if(b-a==k+1){is[a]=1;tt++;}
		}
	int Min,Max;Min=n;Max=0;
	rep(i,1,n)sum[i]=sum[i-1]+is[i];
	rep(i,1,n)if(is[i]){Min=i;break;}
	per(i,n,1)if(is[i]){Max=i;break;}
	if(!Max){
		int res=1;
		rep(i,1,n){
			int v=k;if(n-k-i-1<k)v=n-k-i-1;
			//printf("%d %d\n",i,v);
			if(v<0)continue;
			res=(res+Pow(2,v))%jsb;
		}
		printf("%d\n",res);
		return 0;
	}
	int res=0;
	rep(i,1,Min){
		if(i+k+1<=Max)continue;
		int len=min(k,(n-k-1)-i);len-=tt;if(i==Min)len++;
		res=(res+Pow(2,len))%jsb;
	}
	printf("%d\n",res);
	return 0;
}