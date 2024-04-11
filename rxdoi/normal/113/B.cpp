#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

const int Maxn=2000+19,MAX=(int)6e7/26;
int OK[MAX],son[MAX][26],Fl[Maxn],Fr[Maxn];
int cnt=1,Ans;
string s,Be,Ed;

int main()
{
	cin>>s>>Be>>Ed;
	int sL=s.length();
	int bL=Be.length();
	int eL=Ed.length();
	for (int i=0;i<=sL-bL;i++)
	{
		Fl[i]=1;
		for (int j=0;j<bL;j++) if (s[i+j]!=Be[j]) Fl[i]=0;
	}
	for (int i=0;i<=sL-eL;i++)
	{
		Fr[i]=1;
		for (int j=0;j<eL;j++) if (s[i+j]!=Ed[j]) Fr[i]=0;
	}
	for (int i=0;i<=sL-bL&&i<=sL-eL;i++)
		if (Fl[i])
		{
			int x=1;
			for (int j=i;j<sL;j++)
			{
				int ch=s[j];
				if (!son[x][ch]) son[x][ch]=++cnt;
				x=son[x][ch];
				if (Fr[j-eL+1]&&j-i+1>=bL&&j-i+1>=eL) if (!OK[x]) OK[x]=1,Ans++;
			}
		}
	printf("%d\n",Ans);
}