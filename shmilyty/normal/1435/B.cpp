#include<bits/stdc++.h>
using namespace std;
int t,n,m,belong[250001],col[501];
vector<int> row[501]; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			row[i].clear();
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
			{
				int a;
				scanf("%d",&a);
				row[i].push_back(a);
				belong[a]=i;
			}
		for(int i=1;i<=m;i++)
			for(int l=1;l<=n;l++)
			{
				int a;
				scanf("%d",&a);
				if(i==1)
					col[l]=belong[a];
			}
		for(int i=1;i<=n;i++)
		{
			for(int l=0;l<row[col[i]].size();l++)
				cout<<row[col[i]][l]<<" ";
			cout<<endl;
		}
	}
	return 0;
}