#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int N=100010;
const int inf=2147483647;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
int n,d,a[N];
double f[N][10];
int g[N][10][2],mx[10];
vector<int>ans;
void w(int x,int y)
{
	if(!x)return;
	w(g[x][y][0],g[x][y][1]);
	ans.push_back(a[x]);
}
int main()
{
	n=read(),d=read();
	for(int i=0;i<=n;i++)
	for(int j=0;j<10;j++)
	f[i][j]=-1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		double t=log((double)a[i]);
		int x=a[i]%10;
		for(int j=0;j<10;j++)
		{
			if(mx[j])
			{
				if(f[mx[j]][j]+t>f[i][j*x%10])
				f[i][j*x%10]=f[mx[j]][j]+t,g[i][j*x%10][0]=mx[j],g[i][j*x%10][1]=j;
			}
		}
		if(t>f[i][x])f[i][x]=t,g[i][x][0]=g[i][x][1]=0;
		for(int j=0;j<10;j++)
		if(f[i][j]>f[mx[j]][j])mx[j]=i;
	}
	if(!mx[d])return puts("-1"),0;
	w(mx[d],d);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
	return 0;
}