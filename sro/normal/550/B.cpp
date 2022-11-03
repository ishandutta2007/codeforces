#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt=0;
int n,l,r,x;
int c[16];
inline int panduan(int sum,int choosingjay)
{
	if((sum<l)||(sum>r)) return 0;
	bool choose[16];
	int maxv=-2147483647,minv=2147483647;
	int ccnt=0;
	for(int i=n-1;i>=0;i--)
	{
		if(choosingjay&1)
		{
			ccnt++;
			if(c[i]>maxv)maxv=c[i];
			if(c[i]<minv)minv=c[i];
		}
		choosingjay>>=1;
	}
	if(maxv-minv<x)return 0;
	return 1;
}

inline void to_sum(int choosedn,int nown,int sum,int choosingjay)
{
	if(nown==n)
	{
		if(choosedn==1||choosedn==0) return;
		else cnt+=panduan(sum,choosingjay);
		return;
	}
	else
	{
		to_sum(choosedn+1,nown+1,sum+c[nown],(choosingjay<<1)+1);
		to_sum(choosedn,nown+1,sum,(choosingjay<<1));
	}
}

int main()
{
	scanf("%d %d %d %d",&n,&l,&r,&x);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	to_sum(0,0,0,0);
	printf("%d",cnt);
	return 0;
}