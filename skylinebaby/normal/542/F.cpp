#include<bits/stdc++.h>
using namespace std;
vector<int> a[105];
int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i = 0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
	}
	int ans = 0;
	for(int i = 1;i<t;i++)
	{
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		for(int j = 0;j<a[i].size();j+=2)
		{
			if(j+1<a[i].size()) a[i+1].push_back(a[i][j]+a[i][j+1]);
			else a[i+1].push_back(a[i][j]);
		}
	}
	for(int i = 0;i<a[t].size();i++) ans = max(ans,a[t][i]);
	printf("%d\n",ans);
	return 0;
}