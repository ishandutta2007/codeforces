#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k;
int p[MAXN];
vector<int> G[MAXN];
bool check[MAXN];
int main()
{
	memset(check,false,sizeof(check));
	memset(p,0,sizeof(p));
	scanf("%d",&n);
	p[1]=0;
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		G[i].push_back(x);
		G[x].push_back(i);
		check[x]=true;
		p[i]=x;
	}
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		if(check[i])
		{
			int cnt=0;
			for(int j=0;j<G[i].size();j++)
				if(!check[G[i][j]]) cnt++;
			if(cnt<3) {f=false; break;}
		}
	}
	if(f) puts("Yes"); else puts("No");
	return 0;
}