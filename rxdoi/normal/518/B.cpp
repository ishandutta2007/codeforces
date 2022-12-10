#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

string s,t;
int cs[128],ct[128],n,A1,A2,p;

int main()
{
	cin>>s>>t;
	for (int i=0,_=s.length();i<_;i++) cs[s[i]]++;
	for (int i=0,_=t.length();i<_;i++) ct[t[i]]++;
	For(i,'A','Z'+1) A1+=(p=min(cs[i],ct[i])),cs[i]-=p,ct[i]-=p;
	For(i,'a','z'+1) A1+=(p=min(cs[i],ct[i])),cs[i]-=p,ct[i]-=p;
	For(i,'A','Z'+1) A2+=min(cs[i],ct[i+'a'-'A']);
	For(i,'a','z'+1) A2+=min(cs[i],ct[i+'A'-'a']);
	printf("%d %d\n",A1,A2);
}