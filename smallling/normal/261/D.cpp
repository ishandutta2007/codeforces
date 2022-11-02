#include<cstdio>
#include<algorithm>

#define N 100010

using namespace std;

int n,k,maxb,t,nowans;
int a[N],c[N],f[N];

inline int ask(int x)
{
	int nowans=0;
	for(;x;x-=x&-x)nowans=max(nowans,c[x]);
	return nowans;
}

inline void add(int x,int val)
{
	for(;x<=maxb;x+=x&-x)c[x]=max(c[x],val); 
}

int main()
{
	scanf("%d%d%d%d",&k,&n,&maxb,&t);
	if(t>maxb)t=maxb;
	while(k--)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=maxb;i++)f[i]=0,c[i]=0;
		for(int i=1;i<=t;i++)
			for(int j=1;j<=n;j++)
			{
				nowans=ask(a[j]-1)+1;
				if(nowans>f[a[j]])
				{
					f[a[j]]=nowans;
					add(a[j],nowans);
				}
			}
		printf("%d\n",ask(maxb)); 
	}
}