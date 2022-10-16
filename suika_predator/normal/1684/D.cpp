#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		vector<int> a(n+5),vis(n+5,1);
		vector<pair<int,int>> b(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=make_pair(-a[i]-i,i);
		}
		sort(b.begin()+1,b.begin()+n+1);
		for(int i=1;i<=k;i++)
		{
			vis[b[i].second]=0;
		}
		long long s=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				s+=a[i]+cnt;
			}
			else cnt++;
		}
		cout<<s<<endl;
	}
	
	return 0;
}