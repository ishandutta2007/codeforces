#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bitset<300000000> f;
int main()
{
	int l,r;scanf("%d%d",&l,&r);
	int res=0;if(l<=2&&2<=r)res++;
	for(int i=3;i*i<=r;i+=2)if(!f[i])for(int j=i*i;j<=r;j+=i+i)f[j]=1;
	for(int i=5;i<=r;i+=4)res+=((!f[i])&&(i>=l));printf("%d\n",res);
	return 0;
}