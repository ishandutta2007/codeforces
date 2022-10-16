#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
string str,buf;
int vis1[50],vis2[50];
int main()
{
	cin>>str;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>buf;
		if(buf==str)
		{
			printf("YES\n");
			return 0;
		}
		vis1[buf[1]-'a']=1;
		vis2[buf[0]-'a']=1;
	}
	if(vis1[str[0]-'a']&&vis2[str[1]-'a'])
		cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}