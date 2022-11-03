#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

string s[64];
int n,m;
int isother(int c)
{return ((c=='#'||c=='*'||c=='&'));}

int _find_()
{
	unsigned int g1[64],g2[64],g3[64];
	for(int i=0;i<n;i++)
	{
		int minv;
		minv=1000000000;
		for(int j=0;j<m;j++)
			if(isdigit(s[i][j]))
			{
				minv=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(isdigit(s[i][j]))
			{
				minv=min(minv,m-j);
				break;
			}
		g1[i]=minv;
		minv=1000000000;
		for(int j=0;j<m;j++)
			if(islower(s[i][j]))
			{
				minv=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(islower(s[i][j]))
			{
				minv=min(minv,m-j);
				break;
			}
		g2[i]=minv;
		minv=1000000000;
		for(int j=0;j<m;j++)
			if(isother(s[i][j]))
			{
				minv=j;
				break;
			}
		for(int j=m-1;j>=0;j--)
			if(isother(s[i][j]))
			{
				minv=min(minv,m-j);
				break;
			}
		g3[i]=minv;
	}
	unsigned int minvv=1000000000;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if((i!=j)&&(j!=k)&&(i!=k)&&((g1[i]+g2[j]+g3[k])<minvv))
					minvv=(g1[i]+g2[j]+g3[k]);
	return minvv;
}

int main()
{
	cin>>n>>m;
	set<int> gue,g2,gw;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cout<<_find_()<<endl;
	return 0;
}