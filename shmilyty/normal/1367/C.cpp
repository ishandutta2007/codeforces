#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int t,n,k;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		int ans=0;
		scanf("%d%d",&n,&k);
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
				v.push_back(i+1);
		if(v.size()==0)
		{
			if(n%(k+1)==0)
				cout<<n/(k+1)<<endl;
			else
				cout<<n/(k+1)+1<<endl;
			continue;
		}
		for(int i=1;i<=v[0];i+=(k+1))
			ans++;
		for(int i=0;i<v.size()-1;i++)
			ans+=max(v[i+1]-v[i]-1-k,0)/(k+1);
		for(int i=v[v.size()-1];i<=n;i+=(k+1))
			ans++;
		cout<<ans-2<<endl; 
	}
	return 0;
}