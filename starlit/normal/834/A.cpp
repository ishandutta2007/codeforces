#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char fr,to;
string st="^>v<^>v<";
int tms,pre;
bool c,n;
int main()
{
	scanf("%c %c%d",&fr,&to,&tms);
	for(int i=0;i<4;i++)
	if(st[i]==fr)pre=i;
	if(st[pre+tms%4]==to)c=1;
	pre+=4;
	if(st[pre-tms%4]==to)n=1;
	if(c^n)
	{
		if(c)puts("cw");
		else puts("ccw");
	}
	else puts("undefined");
}