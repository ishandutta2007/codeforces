#include<bits/stdc++.h>
using namespace std;
char s[233];
char a[233][233];
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n>>(s+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]='=';
		vector<int> tmp;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='2')tmp.push_back(i);
			/*
			else
			{
				for(int j=1;j<=n;j++)
				{
					a[i][j]=a[j][i]='=';
				}
			}
			*/
		}
		if(tmp.size()==1 or tmp.size()==2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<(int)tmp.size();i++)
		{
			a[tmp[i]][tmp[(i+1)%tmp.size()]]='+';
			a[tmp[(i+1)%tmp.size()]][tmp[i]]='-';
		}
		for(int i=1;i<=n;i++)a[i][i]='X';
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}