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

string S;
int Len,cur,Ans;

int Check(int L,int R)
{
	string T=S;
	T=T.erase(L,R-L+1);
	return T=="CODEFORCES";
}

int main()
{
	cin>>S;
	Len=S.length();
	For(L,0,Len) For(R,L,Len) if (Check(L,R)) Ans=1;
	puts(Ans?"YES":"NO");
}