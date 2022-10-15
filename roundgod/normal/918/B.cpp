#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
using namespace std;
int n,m;
map<string,string> mp;
string str1,str2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>str1>>str2;
		mp[str2]=str1;
	}
	for(int i=0;i<m;i++)
	{
		cin>>str1>>str2;
		int k=str2.size();
		str2=str2.substr(0,k-1);
		cout<<str1<<' '<<str2<<"; #"<<mp[str2]<<endl;
	}
	return 0;
}