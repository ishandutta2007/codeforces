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
int n,f=1;

int main()
{
	cin>>s>>t;
	n=s.length();
	For(i,0,n) if (s[i]!='z') {f=0;break;}
	if (f) return puts("No such string"),0;
	s[n-1]++;
	for (int i=n-1;~i;i--) if (s[i]=='z'+1) s[i]='a',s[i-1]++;else break;
	if (s==t) return puts("No such string"),0;
	cout<<s<<endl;
}