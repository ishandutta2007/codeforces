#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int T,n,l0,l1,l2,l3=2;
string s0="What are you doing at the end of the world? Are you busy? Will you save us?",
s1="What are you doing while sending \"",s2="\"? Are you busy? Will you send \"",s3="\"?";
long long k,pow[N];//0:>>
char dfs(int n,long long k)
{
	if(!n)return k<=l0?s0[k-1]:'.';
	if(k<=l1)
	return s1[k-1];
	k-=l1;
	if(k<=pow[n-1]||!pow[n-1])return dfs(n-1,k);
	k-=pow[n-1];
	if(k<=l2)return s2[k-1];
	k-=l2;
	if(k<=pow[n-1]||!pow[n-1])return dfs(n-1,k);
	k-=pow[n-1];
	return k<=l3?s3[k-1]:'.';
}
inline int slen(string s)
{
	for(int i=0;;i++)
	if(s[i]=='\0')return i;
}
int main()
{
	scanf("%d",&T);
	l0=slen(s0);l1=slen(s1);l2=slen(s2);
	pow[0]=l0;
	for(int i=1;;i++)
	{
		pow[i]=2*pow[i-1]+l1+l2+l3;
		if(pow[i]>1e18)break;
	}
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		putchar(dfs(n,k));
	}
}