#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int w,n,m;
int f[MAXN],tmp[MAXN];
string str;
int main()
{
	scanf("%d%d%d",&w,&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		f[x]++; tmp[x]++;
	}
	for(int i=0;i<m;i++)
	{
		cin>>str;
		reverse(str.begin(),str.end());
		for(int j=0;j<(1<<w);j++) f[j]=tmp[j];
		for(int j=0;j<w;j++)
		{
			if(str[j]=='A')
			{
				for(int mask=0;mask<(1<<w);mask++)
					if(mask&(1<<j)) 
					{
						int t=f[mask^(1<<j)];
						f[mask^(1<<j)]+=f[mask];
						f[mask]=t;
					}
			}
			else if(str[j]=='O')
			{
				for(int mask=0;mask<(1<<w);mask++)
					if(mask&(1<<j)) f[mask]=0;
			}
			else if(str[j]=='X')
			{
				;
			}
			else if(str[j]=='a')
			{
				for(int mask=0;mask<(1<<w);mask++)
					if(mask&(1<<j)) f[mask^(1<<j)]=0;
			}
			else if(str[j]=='o')
			{
				for(int mask=0;mask<(1<<w);mask++)
					if(mask&(1<<j)) 
					{
						int t=f[mask];
						f[mask]+=f[mask^(1<<j)];
						f[mask^(1<<j)]=t;
					}
			}
			else
			{
				for(int mask=0;mask<(1<<w);mask++)
					if(mask&(1<<j)) swap(f[mask],f[mask^(1<<j)]);
			}
		}
		ll ans=0;
		for(int mask=0;mask<(1<<w);mask++) ans+=1LL*f[mask]*tmp[mask];
		printf("%lld\n",ans);
	}
	return 0;
}