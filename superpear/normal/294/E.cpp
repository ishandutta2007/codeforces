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

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143
typedef pair<LL,LL> PII;
typedef pair<LL,PII> PIII;

const LL INF=1000000000000000000LL;
const int maxn=5005;

LL ans=INF,QZans,QZsize;
LL size[maxn],insi[maxn],sumto[maxn];
int x[maxn],y[maxn],z[maxn];
int N;
vector<PII> F[maxn];

void dfs1(int s,int fa)
{
	size[s]=1;
	insi[s]=sumto[s]=0;
	LL cs;
	for (int i=0;i<F[s].size();i++)
		if (F[s][i].w1!=fa)
		{
			dfs1(F[s][i].w1,s);
			size[s]+=size[F[s][i].w1];
			insi[s]+=insi[F[s][i].w1];
			if (insi[s]>=ans) return;
			cs=sumto[F[s][i].w1]+(LL)F[s][i].w2*size[F[s][i].w1];
			sumto[s]+=cs;
			insi[s]-=(LL)cs*size[F[s][i].w1];
		}
	insi[s]+=(LL)sumto[s]*(size[s]-1)+sumto[s];
}

void dfs2(int s,int fa,LL nowans)
{
	QZans=min(QZans,nowans);
	for (int i=0;i<F[s].size();i++)
		if (F[s][i].w1!=fa)
			dfs2(F[s][i].w1,s,nowans+(LL)F[s][i].w2*(QZsize-2*size[F[s][i].w1]));
}

PIII getinfo(int ROOT)
{
	dfs1(ROOT,0);
	QZans=INF;
	QZsize=size[ROOT];
	dfs2(ROOT,0,sumto[ROOT]);
	return m_p(size[ROOT],m_p(insi[ROOT],QZans));
	//return pair<size,pair<insidesum,minsumtocore> >
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<N;i++)
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
	for (int i=1;i<N;i++)
	{
		for (int j=0;j<=N;j++) F[j].clear();
		for (int j=1;j<N;j++)
			if (j!=i)
			{
				F[x[j]].p_b(m_p(y[j],z[j]));
				F[y[j]].p_b(m_p(x[j],z[j]));
			}
		PIII ac1=getinfo(x[i]);
		if (ac1.w2.w1>=ans) continue;
		PIII ac2=getinfo(y[i]);
		if (ac2.w2.w1>=ans) continue;
		/*cout<<x[i]<<" "<<y[i]<<endl;
		cout<<ac1.w1<<" "<<ac1.w2.w1<<" "<<ac1.w2.w2<<endl;
		cout<<ac2.w1<<" "<<ac2.w2.w1<<" "<<ac2.w2.w2<<endl;*/
		ans=min(ans,(LL)ac1.w2.w1+ac2.w2.w1+(LL)ac1.w2.w2*ac2.w1+(LL)ac1.w1*ac2.w2.w2+(LL)ac1.w1*ac2.w1*z[i]);
	}
	printf("%I64d\n",ans);

    return 0;
}