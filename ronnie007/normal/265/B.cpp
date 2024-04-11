#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int n;

void input();


int main()
    {
    input();
    return 0;
    }


void input()
    {
	scanf("%d",&n);
	int i;
	int x;
	long long br=0;
	int height=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&x);
		if(x<height)
			{
			br+=(height-x);
			height=x;
			}
		else
			{
			br+=(x-height);
			height=x;
			}
		br++;
		br++;
		//cout<<br<<"\n";
		}
	cout<<br-1<<"\n";
    }