#include<bits/stdc++.h>

using namespace std;

string s;

int last=-1;

int ans;

int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
		{
			ans=max(ans,i-last);
			last=i;
		}
	}
	ans=max(ans,(int)s.length()-last);
	cout<<ans;
}