#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;string s[1000],t;char c;bool v[1000];
char nor(char a)
{
	if('A'<=a&&a<='Z')a=a-'A'+'a';
	return a;
}
bool equal(char a,char b)
{
	return nor(a)==nor(b);
}
void doo(string s)
{
	for(int i=0;i<=(int)t.length()-(int)s.length();i++)
	{
		bool f=1;
		for(int j=i;j<i+s.length();j++)
			if(!equal(s[j-i],t[j]))f=0;
		if(f)for(int j=i;j<i+s.length();j++)v[j]=1;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>t;string _;cin>>_;c=_[0];
	for(int i=0;i<n;i++)doo(s[i]);
	for(int i=0;i<t.length();i++)
		if(v[i])
			if(nor(t[i])==nor(c))
			{
				if(c!='a')if(nor(t[i])==t[i])t[i]='a';else t[i]='A';
				else if(nor(t[i])==t[i])t[i]='b';else t[i]='B';
			}else if(nor(t[i])==t[i])t[i]=c;else t[i]=c-'a'+'A';
	cout<<t<<endl;
	return 0;
}