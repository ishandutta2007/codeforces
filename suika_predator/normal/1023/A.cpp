#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	string s,t;
	cin>>n>>m>>s>>t;
	if(s.length()-1>t.length())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	string pre,suf;
	int ok=0;
	for(auto ch:s)
	{
		if(ch=='*')ok=1;
		else
		{
			if(ok)suf.push_back(ch);
			else pre.push_back(ch);
		}
	}
	if(not ok)
	{
		if(s==t)cout<<"YES\n";
		else cout<<"NO\n";
		return 0;
	}
	for(int i=0;i<(int)pre.length();i++)
	{
		if(pre[i]!=t[i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for(int i=1;i<=(int)suf.length();i++)
	{
		if(suf[suf.length()-i]!=t[t.length()-i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}