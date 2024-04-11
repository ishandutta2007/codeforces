#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		int sum=0;
		for(int i=0;i<s.size();i++)
			sum+=s[i]-'0';
		if(sum==0||sum==s.size())
			cout<<s;
		else
			for(int i=0;i<s.size();i++)
				cout<<10;
		cout<<endl;
	}
	return 0;
}