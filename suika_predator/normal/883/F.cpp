#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
string s[411];
int c[411];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		string sx;
		cin>>sx;
		int t=0;
		for(int j=sx.size()-1;j>=0;--j)
		{
			if(sx[j]=='u')
			{
				t=0;
				s[i].push_back('o');
				s[i].push_back('o');
			}
			else if(sx[j]=='h')
			{
				s[i].push_back('h');
				t=1;
			}
			else if(t==1&&sx[j]=='k')continue;
			else
			{
				t=0;
				s[i].push_back(sx[j]);
			}
		}
	}
	int ct=0;
	for(int i=1;i<=n;++i)
	{
		if(c[i])continue;
		c[i]=++ct;
		for(int j=i+1;j<=n;++j)
		{
			if(s[i]==s[j])
				c[j]=c[i];
		}
	}
	cout<<ct<<endl;
	return 0;
}