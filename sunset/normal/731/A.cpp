#include<bits/stdc++.h>

using namespace std;

int ans;

int main()
{
	string s;
	cin>>s;
	ans=min(26-abs(s[0]-'a'),abs(s[0]-'a'));
	for(int i=1;i<s.length();i++)
	{
		ans+=min(26-abs(s[i]-s[i-1]),abs(s[i]-s[i-1]));
	}
	cout<<ans;
}