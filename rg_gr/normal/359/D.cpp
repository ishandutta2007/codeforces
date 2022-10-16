#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
inline int lcm(int a,int b)
{
	return a>b?b:a;
}
int st[300005][23],log2[300005],mn[300005][23];
inline int queryG(int a,int b)
{
	int k=log2[b-a+1]-1;
	return gcd(st[a][k],st[b-(1<<k)+1][k]);
}
inline int queryL(int a,int b)
{
	int k=log2[b-a+1]-1;
	return lcm(mn[a][k],mn[b-(1<<k)+1][k]);
}
int ans,qaqaqaq[300005];
inline int qaq(int qwq,int n)
{
	int a=0;
	for(int i=1;i+qwq<=n;i++)
	{
		if(queryG(i,i+qwq)==queryL(i,i+qwq))qaqaqaq[a++]=i;
	}
	if(a)return ans=a;
	else return 0;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)st[i][0]=mn[i][0]=read(),log2[i]=log2[i>>1]+1;
	for(int i=1;i<=22;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)st[j][i]=gcd(st[j][i-1],st[j+(1<<i-1)][i-1]),mn[j][i]=lcm(mn[j][i-1],mn[j+(1<<i-1)][i-1]);
	int l=0,r=n-1,qwq=114514;
	while(l<=r)
	{
		int m=l+(r-l>>1);
		if(qaq(m,n))l=m+1,qwq=m;
		else r=m-1;
//		printf("D %d %d\n",l,r);
	}
	printf("%d %d\n",ans,qwq);
	for(int i=0;i<ans;i++)printf("%d ",qaqaqaq[i]);
	return 0;
}