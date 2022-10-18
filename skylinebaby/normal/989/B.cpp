#include<bits/stdc++.h>
using namespace std;
char s[12345];
int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	cin >> s;
	int flag = 0;
	for(int i = p;i<n;i++)
	{
		if (s[i]=='.') 
		{
			flag = 1;
			if(s[i-p]=='.')
			{
				s[i-p]='0';s[i]='1';
			}
			else s[i]='0'+(s[i-p]-'0')^1;
		}
		if (s[i]!=s[i-p]) 
		{
			flag = 1;
			if (s[i-p]=='.') s[i-p]='0'+(s[i]-'0')^1;
		}
	}
	if (flag==0)
	{
		printf("No\n");
		return 0;
	}
	for(int i = 0;i<p;i++)
	{
		if (s[i]=='.') s[i]='0';
	}	
	cout << s;
	return 0;
}