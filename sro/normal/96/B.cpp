#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const __int64 MAXN=(int)1e6*2;
__int64 _4s[20];
__int64 arr[MAXN];
__int64 cnt=0;

inline bool check(int k,int ws)
{
	__int64 ym2,ok=0;
	__int64 ls=k;
	while(ls)
	{
		ym2=ls%2;
		if(ym2)ok++;
		ls>>=1;
	}
	return (ok*2==ws);
}

inline __int64 kch3(int k)
{
	__int64 n=0,ym2,weiq=1;
	int ls=k;
	while(ls)
	{
		ym2=ls%2;
		if(ym2)n+=3*weiq;
		ls/=2;
		weiq*=10;
	}
	return n;
}

__int64 num;

int main()
{
	_4s[0]=0;
	for(int i=1;i<19;i++)_4s[i]=_4s[i-1]*10+4;
	for(int i=2;i<=14;i+=2)
	{
		int mxv=(1<<i);
		for(int j=0;j<mxv;j++)
		{
			if(check(j,i))
			{
				arr[cnt++]=_4s[i]+kch3(j);
			}
		}
	}
	__int64 MAXV=1e12;
	__int64 n,minv=MAXV;
	cin>>n;
	for(int i=0;i<cnt;i++)
		if(arr[i]>=n&&arr[i]<minv)
			minv=arr[i];
	cout<<minv<<endl;
	return 0; 
}