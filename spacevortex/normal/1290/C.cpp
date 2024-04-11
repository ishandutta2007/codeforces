#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=6e5+50;
int n,K,ans=0;
char s[N];
int A[N],fa[N],fw[N],dis[N],siz[N][2],tag[N];
vector<int> vec[N],h[N];
int getft(int x)
{
	if(x==fa[x]) return x;
	int ret;
	ret=getft(fa[x]);
	dis[x]=dis[fa[x]]^fw[x];
	fw[x]^=fw[fa[x]];
	return fa[x]=ret;
}
int qry(int id)
{
	if(tag[id]==-1) return min(siz[id][0],siz[id][1]);
	else return siz[id][tag[id]];
}
int main()
{
	int i,j,num,x,a,b,af,bf,w;
	scanf("%d%d",&n,&K);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) A[i]=s[i]-48;
	for(i=1;i<=K;i++)
	{
		num=rd();
		for(j=1;j<=num;j++)
		{
			x=rd();
			vec[i].pb(x);
			h[x].pb(i);
		}
	}
	for(i=1;i<=K;i++)
	{
		fa[i]=i;dis[i]=0;siz[i][0]=1;tag[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		//printf("solve%d\n",i);
		num=h[i].size();
		if(num==1)
		{
			a=h[i][0];
			//printf("A %d\n",a);
			af=getft(a);
			ans-=qry(af);
			w=A[i]^dis[a];
			tag[af]=w;
			ans+=qry(af);
		}
		if(num==2)
		{
			a=h[i][0];b=h[i][1];
			af=getft(a);bf=getft(b);
			if(af!=bf)
			{
				ans-=qry(af)+qry(bf);
				w=A[i]^1^dis[a]^dis[b];
				fa[af]=bf;fw[af]=w;dis[af]=w;
				if(w==1)
				{
					siz[bf][0]+=siz[af][1],siz[bf][1]+=siz[af][0];
				}
				else 
				{
					siz[bf][0]+=siz[af][0],siz[bf][1]+=siz[af][1];
				}
				
				if(tag[af]!=-1) tag[bf]=tag[af]^w;
				//printf("S%d %d %d %d\n",bf,siz[bf][0],siz[bf][1],tag[bf]);
				ans+=qry(bf);
			}
		}
		
		printf("%d\n",ans);
		//if(i==7) exit(0);
	}
	return 0;
}