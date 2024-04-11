#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

map<string,int> Map;
string s,can,tmp;
int k,tot,Ans,cnt,son[1500*1500+19][26];
string str[1500*1500+19];

int main()
{
	cin>>s>>can;
	scanf("%d",&k);
	int Len=s.length();
	for (int i=0;i<Len;i++)
	{
		tot=0;int x=0;
		for (int j=i;j<Len;j++) 
		{
			tot+=(can[s[j]-'a']-'0')^1;
			if (tot>k) break;
			if (!son[x][s[j]-'a']) son[x][s[j]-'a']=++cnt,Ans++;
			x=son[x][s[j]-'a'];
		}
	}
	printf("%d\n",Ans);
}