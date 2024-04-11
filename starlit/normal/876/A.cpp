#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,a,b,c,mp[3][3],now,mn,pos,ans;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	mp[0][1]=mp[1][0]=a,mp[0][2]=mp[2][0]=b,mp[1][2]=mp[2][1]=c;
	for(int i=1;i<n;i++)
	{
		mn=200;
		for(int j=0;j<3;j++)
		if(j!=now&&mp[now][j]<mn)
		mn=mp[now][j],pos=j;
		now=pos,ans+=mn;
	}
	printf("%d",ans);
}