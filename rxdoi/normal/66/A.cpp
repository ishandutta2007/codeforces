#include<cstdio>
#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

string S;

int cmp(string S,string T)
{
	if (S.length()!=T.length()) return S.length()<T.length();
	For(i,0,S.length()) if (S[i]!=T[i]) return S[i]<T[i];
	return 1;
}

int main()
{
	cin>>S;
	if (cmp(S,"127")) return puts("byte"),0;
	if (cmp(S,"32767")) return puts("short"),0;
	if (cmp(S,"2147483647")) return puts("int"),0;
	if (cmp(S,"9223372036854775807")) return puts("long"),0;
	puts("BigInteger");
}