#include<bits/stdc++.h>
using namespace std;
int t,n,m;
string s[11];
vector<string> ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
        ans.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			ans.push_back(s[i]);
		}
		for(int i=0;i<s[1].size();i++)
		{
			string ss=s[1];
			for(int l='a';l<='z';l++)
				if(s[1][i]!=l)
				{
					ss[i]=l;
					ans.push_back(ss);
				}
			ss[i]=s[1][i];
		}	
		bool out=1;
		for(string i:ans)
		{
			bool flag=1;
			for(int l=1;l<=n;l++)
			{
				bool d=0;
				for(int j=0;j<s[l].size();j++)
					if(s[l][j]!=i[j])
					{
						if(d)
						{
							flag=0;
							break;
						}
						d=1;
					}
				if(!flag)
					break;
			}
			if(flag)
			{
				cout<<i<<endl;
				out=0;
				break;
			}
		}
		if(out)
			puts("-1");
	}
	return 0;
}