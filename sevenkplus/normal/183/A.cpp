#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int x=1,y=1;char s[20];
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		scanf("%s",s);int n=strlen(s);
		if(n==4)x++,y++;else
		if(s[0]=='U'&&s[1]=='L'||s[0]=='D'&&s[1]=='R')x++;else y++;
	}
	cout<<(ll)x*y<<endl;
	return 0;
}