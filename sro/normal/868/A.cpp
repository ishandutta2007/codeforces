#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map> 
using namespace std;
string s;
int n;
map<char,bool>mp1,mp2;
int main()
{
	cin>>s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		if(str==s)
		{
			printf("YES");
			return 0;
		}
		mp1[str[1]]=mp2[str[0]]=true;
	}
	if(mp1[s[0]] && mp2[s[1]])printf("YES");else printf("NO");
	return 0;
}