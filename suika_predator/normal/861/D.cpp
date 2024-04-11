#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n,m;
inline string sub(string str,int a,int b)
{
	string tmp="";
	for(int i=a;i<=b;i++)
		tmp+=str[i];
	return tmp;
}
map<string,int> table;
map<string,int> tmpt;
string num[75000];
char buf[13];
int main()
{
	scanf("%d",&n);
	for(int t=1;t<=n;t++)
	{
		scanf("%s",buf);
		num[t]=buf;
		for(int i=0;i<=8;i++)
		{
			for(int j=i;j<=8;j++)
			{
				tmpt[sub(num[t],i,j)]=1;
			}
		}
		for(auto ss:tmpt)table[ss.first]++;
		tmpt.clear();
	}
	for(int t=1;t<=n;t++)
	{
		bool flag=0;
		for(int len=1;len<=9;len++)
		{
			for(int i=0;i+len-1<=8;i++)
			{
				if(table[sub(num[t],i,i+len-1)]==1)
				{
					printf("%s\n",sub(num[t],i,i+len-1).c_str());
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
	}
	return 0;
}