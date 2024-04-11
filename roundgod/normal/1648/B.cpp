#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c;
int nxt[MAXN],cnt[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for(int i=1;i<=c;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[x]=1;
		}
		if(!cnt[1])
		{
			puts("No");
			continue;
		}
		nxt[c+1]=c+1;
		for(int i=c;i>=1;i--)
		{
			if(cnt[i]) nxt[i]=i;
			else nxt[i]=nxt[i+1];
		}
		bool f=true;
		for(int i=1;i<=c;i++)
		{
			if(!cnt[i]) continue;
			for(int j=i;j<=c;j+=i)
			{
				int r=min(c,j+i-1);
				if(nxt[j]>r) continue;
				if(!cnt[nxt[j]/i]) {f=false; break;}
			}
		}
		if(f) puts("Yes"); else puts("No");
	}
	return 0;
}