#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int ans=0;
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int b[10]={0};
		for (int x=0;x<s.length();x++)
		{
			b[int(s[x])-48]++;
		}
		bool p=0;
		for (int x=0;x<=k;x++)
		{
			if (b[x]==0)
			{
				p=1;
				break;
			}
		}
		if (p==0)
			ans++;
	}
	cout<<ans<<endl;
}