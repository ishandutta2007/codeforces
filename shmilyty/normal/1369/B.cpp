#include<bits/stdc++.h>
using namespace std;
int t,n,len1,len0;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>s;
		len0=n-1;
		len1=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
			{
				len0=i-1;
				break;
			}	
		for(int i=s.size()-1;i>=0;i--)
			if(s[i]=='0')
			{
				len1=i+1;
				break;
			}
		for(int i=0;i<=len0;i++)
			cout<<0;
		if(len0+1!=len1)
			cout<<0;
		for(int i=len1;i<n;i++)
			cout<<1;
		cout<<endl;
	}
	return 0;
}