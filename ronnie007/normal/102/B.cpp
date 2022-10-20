#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int n;
string a;

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
	cin>>a;
	n=a.size();
    }



void solve()
	{
	int i;
	int j;
	string help;
	int br=0;
	int sm=0;
	while(n>1)
		{
		br++;
		sm=0;
		for(i=0;i<n;i++)
			{
			sm+=a[i]-'0';
			}
		help.clear();
		n=0;
		while(sm>0)
			{
			help+=(sm%10+'0');
			sm=sm/10;
			n++;
			}
		a=help;
		//cout<<a<<"\n";
		}
	printf("%d\n",br);
	}