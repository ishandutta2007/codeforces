#include<bits/stdc++.h>
using namespace std;
int n,t,ans,belong[200001];
string s;
vector<int> v[2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1;
		cin>>s;
		v[0].clear();
		v[1].clear();
		v[s[0]-'0'].push_back(1);
		belong[0]=1;
		for(int i=1;i<n;i++)
		{
			int tar=(s[i]-'0')^1;
			if(v[tar].empty())
			{
				belong[i]=++ans;
				v[tar^1].push_back(ans);	
			}	
			else
			{
				int tmp=v[tar].back();
				belong[i]=tmp;
				v[tar].pop_back();
				v[tar^1].push_back(tmp);
			}
		} 
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			cout<<belong[i]<<" ";
		cout<<endl;
	}
	return 0;
}