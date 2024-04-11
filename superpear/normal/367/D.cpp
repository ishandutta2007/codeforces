#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int N,M,D,cs,xc,ns,ans,sm;
int a[100005],num[35],f[2000005];

int main()
{
	scanf("%d %d %d",&N,&M,&D);
	memset(a,0,sizeof(a));
	for (int i=1;i<=M;i++)
	{
		scanf("%d",&cs);
		for (int j=1;j<=cs;j++)
		{
			scanf("%d",&xc);
			a[xc]=i;
		}
	}
	memset(num,0,sizeof(num));
	ns=0;
	for (int i=1;i<=D;i++)
	{
		num[a[i]]++;
		ns|=(1<<(a[i]-1));
	}
	memset(f,0,sizeof(f));
	for (int i=1;i<=N-D+1;i++)
	{
		f[(1<<M)-1-ns]=1;
		--num[a[i]];
		if (num[a[i]]==0) ns-=(1<<(a[i]-1));
		++num[a[D+i]];
		if (num[a[D+i]]==1) ns+=(1<<(a[D+i]-1));
	}
	for (int i=(1<<M)-1;i>0;i--)
		if (f[i]==1)
			for (int j=1;j<=M;j++)
				if ((i>>(j-1))%2==1)
					f[i-(1<<(j-1))]=1;
	ans=maxlongint;
	for (int i=0;i<(1<<M);i++)
		if (f[i]==0)
		{
			sm=0;
			for (int j=1;j<=M;j++)
				if ((i>>(j-1))%2==1) ++sm;
			ans=min(ans,sm);
		}
	printf("%d\n",ans);


    return 0;
}