#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m;
double ans;
int main()
{
	ans=INF;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans=min(ans,(double)x/y*m);
	}
	printf("%.10f\n",ans);
	return 0;
}