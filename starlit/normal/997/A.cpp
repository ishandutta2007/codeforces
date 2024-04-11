#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300005
using namespace std;
int n,x,y,t;
char S[N];
int main()
{
	scanf("%d%d%d%s",&n,&x,&y,S);
	S[n]='1';
	for(int i=0;i<n;i++)
	if(S[i]=='0'&&S[i+1]=='1')t++;
	if(!t)return puts("0"),0;
	if(x<y)printf("%I64d",1ll*x*(t-1)+y);
	else printf("%I64d",1ll*y*t);
}