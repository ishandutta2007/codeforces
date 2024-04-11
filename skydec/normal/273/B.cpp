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
#define MAXN 210000
int jsb;int n;
struct cao
{
	int x,y;
}data[MAXN*2];
bool cmp(cao a,cao b){return a.x<b.x;}
int res[MAXN];
int p[MAXN];
int Pow(int a,int b)
{
	//printf("%d %d\n",a,b);
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;
	return c;
}
void init()
{
	rep(i,2,n)if(!p[i])
	rep(j,2,n/i)if(!p[j*i])p[j*i]=i;
}
int main()
{
	scanf("%d",&n);n*=2;init();
	rep(i,1,n){scanf("%d",&data[i].x);data[i].y=i%(n/2);}
	rep(i,n/2+1,n)if(data[i].x==data[i-n/2].x)res[2]--;
	scanf("%d",&jsb);
	sort(data+1,data+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int j=i;while(j<n&&data[j+1].x==data[i].x)j++;
		rep(k,2,j-i+1)res[k]++;
		i=j;
	}
	int ans=1;
	for(int i=n;i>=2;i--)
	if(p[i]){res[p[i]]+=res[i];res[i/p[i]]+=res[i];}
	else ans=ans*1ll*Pow(i,res[i])%jsb;
	printf("%d\n",ans);
	return 0;
}