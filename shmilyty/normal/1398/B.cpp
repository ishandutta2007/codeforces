#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
string s;
vector<int> v;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		v.clear();
		ans=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
				cnt++;
			else
			{
				v.push_back(cnt);
				cnt=0;
			}
		if(cnt)
		{
			v.push_back(cnt);
			cnt=0;
		}
		sort(v.begin(),v.end(),greater<int>());
		for(int i=0;i<v.size();i+=2)
			ans+=v[i];
		cout<<ans<<endl;
	}
	return 0;
}