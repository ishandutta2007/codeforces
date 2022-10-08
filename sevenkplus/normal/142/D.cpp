#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,S[10];bool vr,vg;char s[110];
void add(int x)
{
	for(int i=0;i<10;i++)(S[i]+=(x%2))%=(k+1),x/=2;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		int x=-1,y=-1,r=0,g=0;
		for(int j=0;j<m;j++)
			if(s[j]!='-')
			{
				if(s[j]=='R')r=1;
				if(s[j]=='G')g=1;
				if(x==-1)x=j;else
				if(y==-1)y=j;
			}
		if(y!=-1&&r+g==1){if(m>2)vr|=r,vg|=g;}else
		if(y!=-1)add(abs(x-y)-1);else
		if(x!=-1){if(m>1)vr|=r,vg|=g;}
	}
	if(vr&&vg)puts("Draw");else
	if(vg&&!vr)puts("First");else
	if(vr&&!vg)puts("Second");else
	{
		bool F=0;
		for(int i=0;i<10;i++)if(S[i])F=1;
		puts(F?"First":"Second");
	}
	return 0;
}