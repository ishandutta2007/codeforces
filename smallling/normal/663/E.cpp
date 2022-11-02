#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,N,cnt;
int b[100010];
long long Ans,ans[1<<20],f[1<<20],g[1<<20];

inline char getnext()
{
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch;
}

void FWT(long long *a,int f)
{
	if(!f)
	{
		for(int i=1;i<N;i<<=1)
			for(int j=0;j<N;j+=i<<1)
				for(int k=0;k<i;k++)
				{
					long long x=a[j+k],y=a[j+k+i];
					a[j+k]=x+y;
					a[j+k+i]=x-y;
				}
	}
	else
	{
		for(int i=1;i<N;i<<=1)
			for(int j=0;j<N;j+=i<<1)
				for(int k=0;k<i;k++)
				{
					long long x=a[j+k],y=a[j+k+i];
					a[j+k]=(x+y)/2;
					a[j+k+i]=(x-y)/2;
				}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch=getnext();
			if(ch=='1')b[j]+=1<<(i-1);
		}
	for(int i=1;i<=m;i++)
		f[b[i]]++;
	N=1<<n;
	for(int i=0;i<N;i++)
	{
		cnt=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))cnt++;
		g[i]=min(cnt,n-cnt);
	}
	FWT(f,0);
	FWT(g,0);
	for(int i=0;i<N;i++)
		ans[i]=f[i]*g[i];
	FWT(ans,1);
	Ans=1000000000000000ll;
	for(int i=0;i<N;i++)
		Ans=min(Ans,ans[i]);
	printf("%I64d",Ans);
}