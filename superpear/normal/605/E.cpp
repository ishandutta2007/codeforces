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


double p[1005][1005],ans[1005];
int a[1005][1005],c[1005];
int N;

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]==0) p[i][j]=0; else p[i][j]=double(a[i][j])/100;
		}
	for (int i=1;i<=N;i++) ans[i]=-1;
	ans[N]=0;
	c[1]=N;
	for (int i=2;i<=N;i++)
	{
		double minc=1e10;
		int mink=0;
		for (int j=1;j<=N;j++)
		{
			if (ans[j]!=-1) continue;
			double cs=0;
			double pc=1;
			for (int k=1;k<=i;k++)
			{
				cs+=pc*ans[c[k]]*p[j][c[k]];
				pc*=(1-p[j][c[k]]);
			}
			cs+=1;
			cs/=(1-pc);
			if (cs<minc) minc=cs,mink=j;
		}
		c[i]=mink;
		ans[mink]=minc;
		//cout<<mink<<" "<<minc<<endl;
	}
	printf("%.10f\n",ans[1]);

    return 0;
}