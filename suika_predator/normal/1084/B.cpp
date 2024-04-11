#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	long long s;
	cin>>n>>s;
	vector<int> a(n+5);
	long long all=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		all+=a[i];
	}
	if(s>all)
	{
		cout<<-1<<endl;
		return 0;
	}
	long long l=0,r=*max_element(a.begin(),a.end());
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		long long has=0;
		for(int i=1;i<=n;i++)
		{
			has+=max(0ll,a[i]-mid);
		}
		if(has>=s)l=mid;
		else r=mid-1;
	}
	cout<<min(l,(long long)*min_element(a.begin()+1,a.begin()+n+1))<<endl;
	return 0;
}