#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<unordered_map>
using namespace std;
int n,m;
int a[233333];
unordered_map<int,int> mmp;
inline int phi(int x)
{
	if(mmp[x])return mmp[x];
	int res=1,tmp;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			tmp=i-1;
			x/=i;
			while(x%i==0)
			{
				tmp*=i;
				x/=i;
			}
			res*=tmp;
		}
	}
	if(x==1)
		return mmp[x]=res;
	else
		return mmp[x]=res*(x-1);
}
typedef pair<int,int> pii;
#define mp make_pair
inline pii ksm(int x,int y,int mod)
{
	int bit=1<<30,flag=0;
	long long ret=1;
	while(bit)
	{
		ret*=ret;
		if(ret>mod)flag=1,ret%=mod;
		if(y&bit)
		{
			ret*=x;
			if(ret>mod)flag=1,ret%=mod;
		}
		bit>>=1;
	}
	return mp(ret,flag);
}
int calc(int l,int r,int mod)
{
	if(l>r)return 1;
	if(mod==1)return 1;
	pii _=ksm(a[l],calc(l+1,r,phi(mod)),mod);
	int tmp=_.first;
	//cout<<l<<' '<<mod<<' '<<tmp<<endl;
	return tmp+mod*(_.second);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int q,l,r;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",calc(l,r,m)%m);
	}
	return 0;
}