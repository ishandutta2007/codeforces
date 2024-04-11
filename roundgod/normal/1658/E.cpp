#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][MAXN];
bool win[MAXN][MAXN];
bool cmp(P p,P q)
{
	return a[p.F][p.S]>a[q.F][q.S];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	vector<P> v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			v.push_back(P(i,j));
	sort(v.begin(),v.end(),cmp);
	int mini1=INF,mini2=INF,maxi1=-INF,maxi2=-INF;
	memset(win,false,sizeof(win));
	for(int i=0;i<n*n;i++)
	{
		P p=v[i];
		int val1=max(p.F+p.S-mini1,p.F-p.S-mini2);
		int val2=max(maxi1-(p.F+p.S),maxi2-(p.F-p.S));
		if(max(val1,val2)<=k)
		{
			win[p.F][p.S]=true;
			mini1=min(mini1,p.F+p.S);
			maxi1=max(maxi1,p.F+p.S);
			mini2=min(mini2,p.F-p.S);
			maxi2=max(maxi2,p.F-p.S);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(win[i][j]) printf("M"); else printf("G");
		puts("");
	}
	return 0;
}