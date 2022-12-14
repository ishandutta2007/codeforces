#include <bits/stdc++.h>

using namespace std;
char name[1000];

vector<pair<int,string> > vec[1000000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%s %d %d",name,&x,&y);
		string s=name;
		vec[x].push_back(make_pair(-y,s));
	}
	for (int i=1;i<=m;i++)
	{
		sort(vec[i].begin(),vec[i].end());
		bool p=1;
		for (int j=2;j<min(3,(int)vec[i].size());j++)
		{
			if (vec[i][j].first==vec[i][j-1].first)
				p=0;
		}
		if (p)
			cout<<vec[i][0].second<<" "<<vec[i][1].second<<'\n';
		else
			printf("?\n");
				
	}
}