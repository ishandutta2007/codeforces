#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int n,k,i,sum;
char ch[N];
int main()
{
	scanf("%d%s",&k,ch);
	n=strlen(ch);
	sort(ch,ch+n);
	for(i=0;i<n;i++)
	sum+=ch[i]-'0';
	for(i=0;i<n&&sum<k;i++)
	sum+='9'-ch[i];
	printf("%d",i);
}