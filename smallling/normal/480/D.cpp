#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
	int in,out,w,s,v;
}a[550];

int n,s,nowt,noww;
int f[550][1010],g[1010];

inline int cmp(const lhy &a,const lhy &b)
{
	if(a.out==b.out)return a.in>b.in;
	return a.out<b.out;
}

int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&a[i].in,&a[i].out,&a[i].w,&a[i].s,&a[i].v);
	a[++n]=(lhy){0,2*n,0,s,0};
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int w=a[i].w;w<=s;w++)
		{
			nowt=a[i].in;
			g[nowt]=0;
			noww=min(w-a[i].w,a[i].s);
			for(int j=1;j<i;j++)
				if(a[j].in>=a[i].in)
				{
					while(nowt<a[j].out)nowt++,g[nowt]=g[nowt-1];
					g[nowt]=max(g[nowt],g[a[j].in]+f[j][noww]);
				}
			f[i][w]=g[nowt]+a[i].v;
		}
	}
	printf("%d",f[n][s]);
}