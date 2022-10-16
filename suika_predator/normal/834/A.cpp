#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
char c1,c2;
bool f1,f2;
inline char turn(char c)
{
	if(c=='^')return '>';
	if(c=='>')return 'v';
	if(c=='v')return '<';
	if(c=='<')return '^';
	while(1);
}
inline char turn2(char c)
{
	if(c=='^')return '<';
	if(c=='>')return '^';
	if(c=='v')return '>';
	if(c=='<')return 'v';
	while(1);
}
int main()
{
	scanf(" %c %c",&c1,&c2);
	scanf("%d",&n);
	n%=4;
	char cur=c1;
	for(int i=1;i<=n;i++)
	{
		cur=turn(cur);
	}
	if(cur==c2)f1=1;
	cur=c1;
	for(int i=1;i<=n;i++)
	{
		cur=turn2(cur);
	}
	if(cur==c2)f2=1;
	if(f1&&!f2)printf("cw\n");
	else if((!f1)&&f2)printf("ccw\n");
	else printf("undefined\n");
	return 0;
}