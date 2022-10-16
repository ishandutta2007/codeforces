#include<bits/stdc++.h>
using namespace std;
int t,ans,last1,last2,last3;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		ans=1e9;
		last1=last2=last3=-1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				last1=i;
				if(last2!=-1&&last3!=-1)
					ans=min(ans,i-min(last2,last3)+1);
			}
			if(s[i]=='2')
			{
				last2=i;
				if(last1!=-1&&last3!=-1)
					ans=min(ans,i-min(last1,last3)+1);
			}
			if(s[i]=='3')
			{
				last3=i;
				if(last1!=-1&&last2!=-1)
					ans=min(ans,i-min(last1,last2)+1);
			}
		}
		if(ans!=1e9)
			cout<<ans<<endl;
		else
			puts("0");
	}
}