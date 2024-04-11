#include<bits/stdc++.h>
using namespace std;
int t,ans,cnt;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		ans=0;
		for(int i=0;i<=9;i++)
			for(int l=0;l<=9;l++)
			{
				cnt=0;
				for(int j=0;j<s.size();j++)
				{
					if(cnt%2)
					{
						if(s[j]-'0'==l)
							cnt++;
					}
					else
					{
						if(s[j]-'0'==i)
							cnt++;
					}		
				}
				ans=max(ans,(i==l?cnt:cnt/2*2));
			}
		cout<<s.size()-ans<<endl;
	}
	return 0;
}