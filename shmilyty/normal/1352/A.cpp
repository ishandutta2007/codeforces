#include<bits/stdc++.h>
using namespace std;
int t,ans;
string s,zero;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		ans=0;
		zero="";
		for(int i=0;i<s.size();i++)
			if(s[i]!='0')
				ans++;
		cout<<ans<<endl;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(s[i]!='0')
				cout<<s[i]<<zero<<" ";
			zero+="0";
		}
		cout<<endl;
	}
	return 0;
}