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
#define jsb 1000000007
int m;
void add(int &x,int y)
{
	x+=y;if(x>=jsb)x-=jsb;
}
struct M
{
	int a[53][53];
	void be()
	{
		rep(i,1,m)a[i][i]=1;
	}
	M operator *(const M &b)const
	{
		M c;memset(c.a,0,sizeof c.a);
		rep(k,1,m)
		rep(i,1,m)
		rep(j,1,m)
		add(c.a[i][j],a[i][k]*1ll*b.a[k][j]%jsb);
		return c;
	}
};
int ch(char u)
{
	if(u<='z'&&u>='a')return u-'a'+1;
	return u-'A'+27;
}
int main()
{
	int k;long long n;
	scanf("%I64d%d%d",&n,&m,&k);M zz;
	rep(i,1,m)rep(j,1,m)zz.a[i][j]=1;
	rep(i,1,k)
	{
		char opt[4];scanf("%s",opt+1);
		zz.a[ch(opt[1])][ch(opt[2])]=0;
	}
	M ans;ans.be();
	n--;for(;n;n>>=1,zz=zz*zz)if(n&1)ans=ans*zz;
	int res=0;
	rep(j,1,m)rep(k,1,m)add(res,ans.a[j][k]);
	printf("%d\n",res);
	return 0;
}