#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<map>
using namespace std;
int n,m;
map<string,string> mp;
string a,b;
char buf[233];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf(" %s",buf);
		a=buf;
		scanf(" %s",buf);
		b=buf;
		mp[b]=a;
	}
	for(int i=1;i<=m;i++)
	{
		scanf(" %s",buf);
		a=buf;
		scanf(" %s",buf);
		b=buf;
		b.pop_back();
		cout<<a<<' '<<b<<"; #"<<mp[b]<<endl;
	}
	return 0;
}