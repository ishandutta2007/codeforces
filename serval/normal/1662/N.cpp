#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int N=1555;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
int n,x[N*N],y[N*N];
LL cx[N],cy[N];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int t=read();
		x[t]=i,y[t]=j;
	}
	LL xy=0,xyy=0;
	for(int i=1;i<n;i++)
	for(int j=1;j<n;j++)
	xy+=(LL)(n-i)*(n-j);
	for(int i=1;i<=n*n;i++)
	{
		xyy+=cx[x[i]]*cy[y[i]];
		cx[x[i]]++,cy[y[i]]++;
	}
	printf("%lld",2LL*xy-xyy);
 	return 0;
}