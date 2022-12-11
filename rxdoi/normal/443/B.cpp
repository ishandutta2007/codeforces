#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string s;
int Len,LL;

int main()
{
	cin>>s>>Len;
	for (int i=0;i<s.length();i++)
		if (!((LL=s.length()+Len-i)&1))
		{
			int Flag=1;
			for (int j=0;j<LL>>1&&i+j+(LL>>1)<s.length();j++)
				if (s[i+j]^s[i+j+(LL>>1)]) {Flag=0;break;}
			if (Flag) break;
		}
	for (int i=0;i<s.length();i++)
		for (int j=i+1;j<s.length();j+=2)
		{
			int Flag=1,L=(j-i+1)>>1;
			for (int k=0;i+k+L<=j;k++)
				if (s[i+k]^s[i+k+L]) {Flag=0;break;}
			if (Flag&&j-i+1>LL) LL=j-i+1;
		}
	printf("%d\n",LL);
}