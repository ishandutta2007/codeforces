#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define P 1000000007
int n,m,a[4];
int ff()
{
	bool F=1;
	for(int i=0;i<4;i++)
	{
		string s;cin>>s;
		int t=0;
		for(int j=(int)s.length()-1;j>=0;j--)
		{
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')t++;
			if(t==m)
			{
				int S=0;
				for(int k=j;k<(int)s.length();k++)(S*=P)+=s[k];
				a[i]=S;
				break;
			}
		}
		if(t<m)F=0;
	}
	if(!F)return 0;
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])return 7;
	if(a[0]==a[1]&&a[2]==a[3])return 1;
	if(a[0]==a[2]&&a[1]==a[3])return 2;
	if(a[0]==a[3]&&a[1]==a[2])return 4;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	int S=7;
	for(int i=0;i<n;i++)S&=ff();
	if(S==7)puts("aaaa");else
	if(S==1)puts("aabb");else
	if(S==2)puts("abab");else
	if(S==4)puts("abba");else puts("NO");
	return 0;
}