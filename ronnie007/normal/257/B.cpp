#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int n,m;


void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
	scanf("%d%d",&n,&m);
    }


void solve()
    {
	int score1=0;
	int score2=0;
	int i;
	if(n<m)swap(n,m);
	int sz=n+m;
	int last=-1;
	if(m%2==1){m--;last=2;}
	else if(n%2==1){n--;last=1;}
	else {n--;last=1;}
	for(i=1;i<sz;i++)
		{
		if(i%2==1)
			{
			if(n>0 && last!=1)
				{
				n--;
				last=1;
				score2++;
				}
			else if(m>0 && last!=2)
				{
				m--;
				last=2;
				score2++;
				}
			else
				{
				if(n>0){n--;last=1;}
				if(m>0){m--;last=2;}
				score1++;
				}
			}
		if(i%2==0)
			{
			if(n>0 && (last==1))
				{
				n--;
				last=1;
				score1++;
				}
			else if(m>0 && (last==2))
				{
				m--;
				last=2;
				score1++;
				}
			else
				{
				if(n>0){n--;last=1;}
				if(m>0){m--;last=2;}
				}
			}
		//printf("%d\n",last);
		}
	printf("%d %d\n",score1,score2);
    }