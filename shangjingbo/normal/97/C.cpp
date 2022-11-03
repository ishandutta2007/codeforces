#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef pair<int,int> PII;

int n;
double P[1000];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<=n;++i)
		scanf("%lf",&P[i]);
	
	double ans=0;
	for (int x=0;x<=n;++x)
		for (int y=0;y<=n;++y)
		{
			int dx=n-2*x;
			int dy=n-2*y;
			if (dx<0 && dy<0) continue;
			
			double res;
			if (dx==0 && dy>=0 || dy==0 && dx>=0)
			{
				res=max(P[x],P[y]);
			}else if (dx==0 && dy<0 || dy==0 && dx<0)
			{
				continue;
			}else
			{
				res=(P[x]*abs(dy)+P[y]*abs(dx))/(double)(abs(dx)+abs(dy));
			}
			
//			printf("%d %d %lf\n",x,y,res);
			
			ans=max(ans,res);
		}
	
	printf("%.10f\n",ans);
	
	return 0;
}