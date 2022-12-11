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

string s[100000+19],S;
int n,x,L;

bool Check(string t)
{
	int l=t.length();
	For(i,0,l)
	{
		while (x<L&&S[x]!=t[i]) x++;
		if (x==L) return 0;x++;
	}
	return 1;
}

int main()
{
	cin>>n;
	For(i,0,n) cin>>s[i];
	cin>>S;L=S.length();
	if (!Check("<3")) return puts("no"),0;
	For(i,0,n) if (!Check(s[i])||!Check("<3")) return puts("no"),0;
	puts("yes");
}