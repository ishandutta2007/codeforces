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

vector<int> tmp;
int N,xc,yc,ans;
vector<int> f[maxn];

void dfs(int s,int fa,int depth)
{
	if (f[s].size()==1)
	{
		tmp.p_b(depth);
		return;
	}
	for (int i=0;i<f[s].size();i++)
		if (f[s][i]!=fa)
			dfs(f[s][i],s,depth+1);
}

int calcans(int s)
{
	tmp.clear();
	dfs(s,1,0);
	sort(tmp.begin(),tmp.end());
	for (int i=1;i<tmp.size();i++)
		tmp[i]=max(tmp[i],tmp[i-1]+1);
	return tmp[tmp.size()-1];
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		scanf("%d %d",&xc,&yc);
		f[xc].p_b(yc);
		f[yc].p_b(xc);
	}
	ans=0;
	for (int i=0;i<f[1].size();i++)
		ans=max(ans,calcans(f[1][i]));
	printf("%d\n",ans+1);

	return 0;
}