#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN];
int main()
{
	int minn=-INF,maxn=INF;
	scanf("%d",&n);
	bool f=true;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y==1) minn=max(minn,1900);
		else maxn=min(maxn,1899);
		if(minn>maxn) f=false;
		minn+=x;
		maxn+=x;
	}
	if(!f) puts("Impossible"); else if(maxn>30000000) puts("Infinity");
	else printf("%d\n",maxn);
	return 0;
}