#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		string s,t;
		cin>>s>>t;
		vector<char> ss,ts;
		int sc=0,tc=0;
		for(auto z:s)
		{
			if(z=='B')sc^=1;
			else if(not ss.empty() and ss.back()==z)
			{
				ss.pop_back();
			}
			else ss.push_back(z);
		}
		for(auto z:t)
		{
			if(z=='B')tc^=1;
			else if(not ts.empty() and ts.back()==z)
			{
				ts.pop_back();
			}
			else ts.push_back(z);
		}
		if(ss==ts and sc==tc)cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	
	return 0;
}