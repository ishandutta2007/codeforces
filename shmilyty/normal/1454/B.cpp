#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<int,int>cnt,pos;
		int n;
 		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			cnt[x]++;
			pos[x]=i;
		}
		int ans=-1;
		for(auto it:cnt)
			if(it.second==1)
			{
				ans=pos[it.first];
				break;
			}
		cout<<ans<<endl;
	}
}