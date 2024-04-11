#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int maxn=100005;

int N,K,xc,yc,xd,yd;
int x[maxn],y[maxn],use[maxn];
PII ex[maxn],ey[maxn];
int o,sm,xx,yy;
int main()
{
	//freopen("C.in","r",stdin);

	scanf("%d %d",&N,&K);
	for (int i=1;i<=N;i++)
	{
		scanf("%d %d %d %d",&xc,&yc,&xd,&yd);
		x[i]=xc+xd;
		y[i]=yc+yd;
	}
	LL ans=6000000000000000000LL;

	for (int i=1;i<=N;i++) ex[i]=m_p(x[i],i);
	for (int i=1;i<=N;i++) ey[i]=m_p(y[i],i);
	sort(ex+1,ex+N+1);
	sort(ey+1,ey+N+1);
	memset(use,0,sizeof(use));
	o=0;
	for (int i=1;i<=K+1;i++)
		for (int j=N-K;j<=N;j++)
			if (i<=j)
				for (int u=1;u<=K+1;u++)
					for (int v=N-K;v<=N;v++)
						if (u<=v)
						{
							sm=0;
							++o;
							for (int e=1;e<i;e++)
							{
								if (use[ex[e].w2]!=o) ++sm;
								use[ex[e].w2]=o;
							}
							for (int e=j+1;e<=N;e++)
							{
								if (use[ex[e].w2]!=o) ++sm;
								use[ex[e].w2]=o;
							}
							for (int e=1;e<u;e++)
							{
								if (use[ey[e].w2]!=o) ++sm;
								use[ey[e].w2]=o;
							}
							for (int e=v+1;e<=N;e++)
							{
								if (use[ey[e].w2]!=o) ++sm;
								use[ey[e].w2]=o;
							}
							//cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<sm<<endl;
							if (sm<=K)
							{
								xx=(ex[j].w1-ex[i].w1);
								if (xx%2==1) xx++;
								if (xx==0) xx=2;
								xx/=2;
								yy=(ey[v].w1-ey[u].w1);
								if (yy%2==1) yy++;
								if (yy==0) yy=2;
								yy/=2;
								ans=min(ans,(LL)xx*yy);
							}
						}
	cout<<ans<<endl;

    return 0;
}