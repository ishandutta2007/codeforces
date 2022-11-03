#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,y,i;
vector<pair<int,int> > v;

int main()
{
	//freopen("tongyonginput.in","r",stdin);
	//freopen("tongyongoutput.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	x=v[0].second;
	y=0;
	for(int i=0;i<n;i++)
	{
		if(v[i].second<x)y++;
		else x=v[i].second;
	}
	printf("%d",y);
	return 0;
}