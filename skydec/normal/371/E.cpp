#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
#define MAXN 310000
LL ans;LL now;int res;
LL f[MAXN];LL sum[MAXN];int n,k;
struct nmb
{
	int a,b;
}data[MAXN];
bool cmp(nmb a,nmb b){return a.a<b.a;}
int main()
{
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&data[i].a);data[i].b=i;}
	sort(data+1,data+1+n,cmp);
	rep(i,1,n)sum[i]=data[i].a+sum[i-1];scanf("%d",&k);
	rep(i,1,k)f[k]+=(i-1)*1ll*(sum[i]-sum[i-1])-(k-i)*1ll*(sum[i]-sum[i-1]);
	ans=f[k];res=k;rep(i,k+1,n)
	f[i]=f[i-1]+(k-1)*1ll*((sum[i]-sum[i-1])+(sum[i-k]-sum[i-k-1]))-2ll*(sum[i-1]-sum[i-k]);
	rep(i,k+1,n)if(f[i]<ans){ans=f[i];res=i;}
	rep(i,res-k+1,res)printf("%d ",data[i].b);return 0;
}