#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int d,m,y;
int cnt[35][13][11];
string s;
int mn=0,md,mo,my;
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	cin>>s;
	for(int i=0;i+9<(int)s.size();i++)
	{
		if(s[i+2]!='-'||s[i+5]!='-')continue;
		bool f=1;
		for(int j=0;j<10;j++)
			if(j!=2&&j!=5&&s[i+j]=='-')
				f=0;
		if(!f)continue;
		int dd=(s[i]-'0')*10+s[i+1]-'0';
		int mm=(s[i+3]-'0')*10+s[i+4]-'0';
		if(s[i+6]!='2'||s[i+7]!='0'||s[i+8]!='1')continue;
		int yy=s[i+9]-'0';
		if(yy<3||yy>5)continue;
		if(mm<1||mm>12)continue;
		if(dd<1||dd>day[mm])continue;
		cnt[dd][mm][yy]++;
		if(cnt[dd][mm][yy]>mn)
			mn=cnt[dd][mm][yy],md=dd,mo=mm,my=yy;
	}
	printf("%02d-%02d-201%d",md,mo,my);
	return 0;
}