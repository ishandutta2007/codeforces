#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int s,b,ans[100010];
pair<int,pair<int,int>>sh[100010];
pair<int,int>ba[100010];

int main()
{
	cin>>s>>b;
	for(int i=1;i<=s;i++)
		scanf("%d",&sh[i].first),sh[i].second.second=i;
	for(int i=0;i<b;i++)
		scanf("%d%d",&ba[i].first,&ba[i].second);
	sort(sh+1,sh+s+1);
	sort(ba,ba+b);
	int ind=0;
	for(int i=1;i<=s;i++)
	{
		sh[i].second.first=sh[i-1].second.first;
		while(ba[ind].first<=sh[i].first && ind<b)
		{
			sh[i].second.first+=ba[ind].second;
			ind++;
		}
	}
	for(int i=1;i<=s;i++)
		ans[sh[i].second.second]=sh[i].second.first;
	for(int i=1;i<=s;i++)
		printf("%d ",ans[i]);
}