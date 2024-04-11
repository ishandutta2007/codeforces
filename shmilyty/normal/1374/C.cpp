#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		string s;
		int ans=0,cnt=0,n;
		scanf("%d",&n);
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
				cnt++;
			if(s[i]==')'&&cnt==0)
			{
				ans++;
				s+=")";
			}
			if(s[i]==')'&&cnt>0)
				cnt--;
		}
		cout<<ans<<endl;		
	}
	return 0;
}