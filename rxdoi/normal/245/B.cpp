#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int vis;
string s;

int main()
{
	cin>>s;
	int Len=s.length();
	for (int i=0;i<Len;i++)
	{
		if (i==0)
		{
			if (s[i]=='h') printf("http://"),i=4;
				else printf("ftp://"),i=3;
			printf("%c",s[i]);
			continue;
		}
		if (!vis&&s[i]=='r'&&s[i+1]=='u')
		{
			vis=1;
			printf(".ru");
			i++;
			if (i+1<Len) printf("/");
			continue;
		}
		printf("%c",s[i]);
	}
}