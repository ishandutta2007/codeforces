#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int rev(int x)
{
	int y=0;
	for(int i=0;i<8;i++)
		if((x>>i)&1)y^=(1<<(7-i));
	return y;
}
int main()
{
	string s;
	getline(cin,s);
	int la=0;
	for(int i=0;i<(int)s.length();i++)
		printf("%d\n",(rev(la)-rev((int)s[i])+256)%256),la=(int)s[i];
	return 0;
}