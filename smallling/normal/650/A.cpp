#include<map>
#include<cstdio>
#include<algorithm>

#define mp make_pair

using namespace std;

map<int,int>cntx,cnty;
map<pair<int,int>,int>cnt;
int n,x,y;
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=cntx[x],ans+=cnty[y];
		ans-=cnt[mp(x,y)];
		cntx[x]++,cnty[y]++;
		cnt[mp(x,y)]++;
	}
	printf("%I64d\n",ans);
}