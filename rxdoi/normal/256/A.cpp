#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=4000+19,MAX=1e6+19;
vector<int> Dis[MAX];
int Ans,A[Maxn],B[Maxn],n,m;

int main()
{
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&B[i]);
		Dis[B[i]].push_back(i);
	}
	for (int i=0;i<=1e6;i++) if (Dis[i].size()) A[n++]=i;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i^j)
			{
				int pre=-1,now=A[i],ii=0,jj=0,Len=0;
				while ((now==A[i]?ii:jj)^Dis[now].size())
					if (now==A[i])
					{
						while (ii<Dis[A[i]].size()&&Dis[A[i]][ii]<=pre) ii++;
						if (ii==Dis[A[i]].size()) break;
						pre=Dis[A[i]][ii];ii++;Len++;now=A[j];
					} else
					{
						while (jj<Dis[A[j]].size()&&Dis[A[j]][jj]<=pre) jj++;
						if (jj==Dis[A[j]].size()) break;
						pre=Dis[A[j]][jj];jj++;Len++;now=A[i];
					}
				Ans=max(Ans,Len);
			}
	for (int i=0;i<n;i++) Ans=max(Ans,(int)Dis[A[i]].size());
	printf("%d\n",Ans);
}