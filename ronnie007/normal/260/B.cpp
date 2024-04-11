#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

string s;
int n;
int a[35][20][5];


void input();
void solve();
int f(int mesec)
	{
	if(mesec==2)return 28;
	if(mesec==1 || mesec==3 || mesec==5 || mesec==7 || mesec==8 || mesec==10 || mesec==12)return 31;
	return 30;
	}

int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
	cin>>s;
	n=s.size();
    }


void solve()
    {
	int i,j,t;
	int d,m,g;
	for(i=1;i<=31;i++)
		{
		for(j=1;j<=12;j++)
			{
			for(t=0;t<3;t++)
				{
				a[i][j][t]=0;
				}
			}
		}
	for(i=0;i<n-9;i++)
		{
		if(s[i+2]=='-' && s[i+5]=='-')
			{
			if(s[i]!='-' && s[i+1]!='-' && s[i+3]!='-' && s[i+4]!='-' && s[i+6]!='-' && s[i+7]!='-' && s[i+8]!='-' && s[i+9]!='-')
				{
				d=(s[i]-'0')*10 + (s[i+1]-'0');
				m=(s[i+3]-'0')*10 + (s[i+4]-'0');
				g=(s[i+6]-'0')*1000 + (s[i+7]-'0')*100 + (s[i+8]-'0')*10 + (s[i+9]-'0');
				if(g==2013 || g==2014 || g==2015)
					{
					if(m>0 && m<=12 && d>0 && d<=f(m))
						{
						a[d][m][g-2013]++;
						}
					}
				}
			}
		}
	int mx=0;
	int fl1=0;
	int fl2=0;
	int fl3=0;
	for(i=1;i<=31;i++)
		{
		for(j=1;j<=12;j++)
			{
			for(t=0;t<3;t++)
				{
				if(mx<a[i][j][t])
					{
					mx=a[i][j][t];
					fl1=i;
					fl2=j;
					fl3=t;
					}
				}
			}
		}
	if(fl1<10)
		{
		printf("0");
		}
	printf("%d-",fl1);
	if(fl2<10)
		{
		printf("0");
		}
	printf("%d-",fl2);

	printf("%d\n",fl3+2013);
    }