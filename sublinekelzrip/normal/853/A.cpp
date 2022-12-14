#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
set<int> s;
pair<int,int> x[300010];
int num[300010];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=k+1;i<=k+n;i++)
		s.insert(i);
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].first;
		x[i].second=i;
	}
	sort(x+1,x+n+1);
	long long ans=0;
	for(int i=n;i>=1;i--)
	{
		num[x[i].second]=*s.lower_bound(x[i].second);
		ans+=x[i].first*1ll*(*s.lower_bound(x[i].second)-x[i].second);
		s.erase(s.lower_bound(x[i].second));
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<num[i]<<' ';
}