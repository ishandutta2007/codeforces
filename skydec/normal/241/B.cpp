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
using namespace std;
typedef long long LL;
#define bit bits
#define MAXN 51000
#define jsb 1000000007
int go[MAXN*34][2];int size[MAXN*34];
int sum[MAXN*34][34];int tw[34];
int n,m;int a[MAXN];int root=1;int tot=1;
inline int bit(int x,int i){return (x>>i)&1;}
int Pow(int x,int y)
{
	int c=1;for(;y;y>>=1,x=x*1ll*x%jsb)
	if(y&1)c=c*1ll*x%jsb;	
	return c;
}
void insert(int A)
{
	int now=root;
	per(i,29,0)
	{
		int d=bit(A,i);
		if(!go[now][d])go[now][d]=++tot;
		now=go[now][d];size[now]++;
		per(j,i,0)if(bit(A,j))sum[now][j]++;
	}
}
int NUM(int A)
{
	int res=0;
	rep(i,1,n)
	{
		int now=1;
		per(j,29,0)
		{
			if(bit(A,j)==0)
			{
				int ufo=go[now][1-bit(a[i],j)];
				if(ufo)
				{
					per(k,j,0)
					{
						if(bit(a[i],k)==0)
						res=(res+tw[k]*1ll*sum[ufo][k]%jsb)%jsb;
						else
						res=(res+tw[k]*1ll*(size[ufo]-sum[ufo][k])%jsb)%jsb;
					}
					res=(res+(size[ufo]*1ll*(tw[j+1])%jsb)*1ll*((A>>(j+1)))%jsb)%jsb;
				}
			}
			now=go[now][bit(A,j)^bit(a[i],j)];
		}
	}
	return res;
}
int QSIZE(int A)
{
	if(!A)return (int)(n*1ll*(n-1)/2);
	LL res=0;
	rep(i,1,n)
	{
		int now=1;
		per(j,29,0)
		{
			if(!bit(A,j))res+=1ll*size[go[now][1-bit(a[i],j)]];
			now=go[now][bit(A,j)^bit(a[i],j)];
		}
	}
	return (int)(res/2);
}
int main()
{
	scanf("%d%d",&n,&m);tw[0]=1;rep(i,1,30)tw[i]=tw[i-1]*2;
	rep(i,1,n){scanf("%d",&a[i]);insert(a[i]);}
	int l=0;int r=(1<<30)-1;int ans=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(QSIZE(mid)<=m)
		{
			r=mid;ans=mid;
		}else l=mid+1;
	}
	if(QSIZE(l)<=m)ans=l;
	
	int res=(m-QSIZE(ans))*1ll*ans%jsb;
	res=(res+NUM(ans)*1ll*Pow(2,jsb-2)%jsb)%jsb;
	printf("%d\n",res);
	return 0;
}