#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

string s;
int len,cnt,flag,last;

int check(int l,int r)
{
	string t=s;
	t=t.erase(l,r-l+1);
	return t=="CODEFORCES";
}

int main()
{
	cin>>s;
	len=s.length();
	for(int l=0;l<len;l++)
		for(int r=l;r<len;r++)
			if(check(l,r))return puts("YES"),0;
	puts("NO");
}