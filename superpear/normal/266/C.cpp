#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

#define m_p make_pair
#define p_b push_back

typedef pair<int,pair<int,int> > PIII;

vector<PIII> ans;
int n,xc,yc,a[1005][1005],sumx[1005],sumy[1005];

int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(sumx,0,sizeof(sumx));
	memset(sumy,0,sizeof(sumy));
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&xc,&yc);
		a[xc][yc]=1;
		++sumx[xc];
		++sumy[yc];
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<i;j++)
			if (sumx[j]>0)
			{
				ans.p_b(m_p(1,m_p(i,j)));
				swap(sumx[i],sumx[j]);			
				for (int k=1;k<=i;k++)
					swap(a[i][k],a[j][k]);
				break;
			}
		for (int j=1;j<i;j++)
			if (sumy[j]==0)
			{
				ans.p_b(m_p(2,m_p(i,j)));
				swap(sumy[i],sumy[j]);
				for (int k=1;k<=i;k++)
					swap(a[k][i],a[k][j]);
				break;
			}
		for (int j=1;j<=i;j++)
		{
			sumx[i]-=a[i][j];
			sumy[j]-=a[i][j];
		}
		for (int j=1;j<i;j++)
		{
			sumx[j]-=a[j][i];
			sumy[i]-=a[j][i];
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d %d %d\n",ans[i].first,ans[i].second.first,ans[i].second.second);
	
	return 0;
}