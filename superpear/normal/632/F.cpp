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

vector<PII> F[2555];
int Flag,N,a[2555][2555],use[2555],dis[2555],from[2555],Max[2555][2555];

void dfs(int *Max,int s,int fa,int mx)
{
	Max[s]=mx;
	for (int i=0;i<F[s].size();i++)
		if (F[s][i].w1!=fa) dfs(Max,F[s][i].w1,s,max(mx,F[s][i].w2));
}

int main()
{
	Flag=1;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=N;i++) if (a[i][i]!=0) Flag=0;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			if (a[i][j]!=a[j][i]) Flag=0;
	if (Flag==1)
	{
		dis[1]=0;
		for (int i=1;i<=N;i++) dis[i]=a[1][i],from[i]=1;
		memset(use,0,sizeof(use));
		use[1]=1;
		for (int i=1;i<N;i++)
		{
			int minc=maxlongint,mink=0;
			for (int j=1;j<=N;j++)
				if ((use[j]==0)&&(dis[j]<minc)) minc=dis[j],mink=j;
			F[mink].p_b(m_p(from[mink],minc));
			F[from[mink]].p_b(m_p(mink,minc));
			use[mink]=1;
			for (int j=1;j<=N;j++)
				if (a[mink][j]<dis[j]) dis[j]=a[mink][j],from[j]=mink;
		}
		memset(Max,0,sizeof(Max));
		for (int i=1;i<=N;i++) dfs(Max[i],i,0,0);
		for (int i=1;i<=N;i++)
			for (int j=i+1;j<=N;j++)
				if (Max[i][j]<a[i][j]) Flag=0;
		/*for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=N;j++)
				cout<<Max[i][j]<<" ";
			cout<<endl;
		}*/
	}	
	if (Flag==1) cout<<"MAGIC"<<endl; else cout<<"NOT MAGIC"<<endl;
	return 0;
}