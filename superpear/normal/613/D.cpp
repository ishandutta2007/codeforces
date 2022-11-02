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

int mulfa[maxn][21];
LL qzans,sum[maxn];
int max1[maxn],min1[maxn],size[maxn],a[maxn],cnt[maxn];
int depth[maxn],biao[maxn],xhr[maxn],fa[maxn],use[maxn],v[maxn];
int N,o,Q,Root,xc,yc,qzi,qzmax,qzmin,sc,ec,oi,Ans;
vector<int> f[maxn];
vector<PII> g[maxn];

//remember that all depths should be greater than 0
int LCA(int x,int y)
{
    if (depth[x]<=depth[y]) swap(x,y);
    for (int i=20;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

void dfs(int s,int fa)
{
    ++o,biao[s]=o;
    depth[s]=depth[fa]+1;
    mulfa[s][0]=fa;
    for (int i=1;i<=20;i++)
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa) dfs(f[s][i],s);
}

bool cmp(int x,int y)
{
    return biao[x]<biao[y];
}

void findans(int S,int fa)
{
	//cout<<S<<" f"<<endl;
	cnt[S]=0;
	int ec=0;
	for (int i=0;i<g[S].size();i++)
		if (g[S][i].w1!=fa)
		{
			if ((xhr[S]==qzi)&&(xhr[g[S][i].w1]==qzi)&&(g[S][i].w2==1)) Ans=-maxlongint;
			//cout<<S<<" "<<g[S][i].w1<<" "<<g[S][i].w2<<endl;
			findans(g[S][i].w1,S);
			if (cnt[g[S][i].w1]==1) ++ec;
		}
	if (ec>1)
	{
		if (xhr[S]==qzi)
			Ans+=ec,cnt[S]=1;
		else
			++Ans,cnt[S]=0;
	}
	else
		if (ec==1)
		{
			if (xhr[S]==qzi) ++Ans;
			cnt[S]=1;
		}
		else
			if (xhr[S]==qzi) cnt[S]=1;
}

int main()
{
	//freopen("D.in","r",stdin);

    //Construct tree
    scanf("%d",&N);
    for (int i=1;i<N;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(mulfa,0,sizeof(mulfa));
    memset(depth,0,sizeof(depth));
    memset(biao,0,sizeof(biao));
    o=0;
    dfs(1,0);

    //For each query
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
        qzi=i;
        //qzi is use for xhr, which indicate whether each node is the input one or the addition one
        scanf("%d",&sc);
        for (int j=1;j<=sc;j++) scanf("%d",&a[j]);
        for (int j=1;j<=sc;j++) xhr[a[j]]=i;
        sort(a+1,a+sc+1,cmp);
        use[a[1]]=i;
        o=1,v[1]=a[1];
        for (int j=2;j<=sc;j++)
        {
            ec=LCA(a[j],a[j-1]);
            if (use[a[j]]!=i)
            {
                ++o,v[o]=a[j];
                use[a[j]]=i;
            }
            if (use[ec]!=i)
            {
                use[ec]=i;
                ++o,v[o]=ec;
            }
        }
        sort(v+1,v+o+1,cmp);
        Root=v[1];
        // Root is root of virtual tree
        for (int j=2;j<=o;j++)
            fa[v[j]]=LCA(v[j],v[j-1]);
        for (int j=2;j<=o;j++)
        {
            oi=depth[v[j]]-depth[fa[v[j]]];
            g[fa[v[j]]].p_b(m_p(v[j],oi));
        }
        // vector<PII> g stores all the edge of the tree

		Ans=0;
        findans(Root,0);
		if (Ans<0) Ans=-1;
		printf("%d\n",Ans);

        for (int j=1;j<=o;j++)
            g[v[j]].clear();
    }

    return 0;
}