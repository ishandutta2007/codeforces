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

const int maxn=1000005;

map<int,int> lsh;
map<int,int>::iterator lsg;
int N,xc,yc,o;
PIII f[maxn];
int g[maxn],ans[maxn];

void mplus(int s)
{
	while (s<=N*2)
	{
		++g[s];
		s+=s&(-s);
	}
}

int getsum(int s)
{
	int ans=0;
	while (s>0)
	{
		ans+=g[s];
		s-=s&(-s);
	}
	return ans;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d %d",&xc,&yc);
		lsh.insert(m_p(yc,0));
		f[i]=m_p(-xc,m_p(yc,i));
	}
	for (lsg=lsh.begin(),o=1;lsg!=lsh.end();lsg++,o++) lsg->w2=o;
	sort(f+1,f+N+1);
	memset(g,0,sizeof(g));
	for (int i=1;i<=N;i++)
	{
		yc=lsh.l_b(f[i].w2.w1)->w2;
		ans[f[i].w2.w2]=getsum(yc);
		mplus(yc);
	}
	for (int i=1;i<=N;i++) printf("%d\n",ans[i]);

	return 0;
}