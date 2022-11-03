#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N,l;
int Ke[64],Sa[64];

int main()
{
	scanf("%d %d",&N,&l);
	for(int i=0;i<N;i++)scanf("%d",&Ke[i]);
	for(int i=0;i<N;i++)scanf("%d",&Sa[i]);
	sort(Ke,Ke+N);
	sort(Sa,Sa+N);
	int j;
	for(j=0;j<N;j++)
		if(Ke[j]!=Sa[j])break;
	if(j==N)return puts("YES"),0;
	for(int i=0;i<l-1;i++)
	{
		for(int j=0;j<N;j++)
		{
			Ke[j]++;
			if(Ke[j]==l)Ke[j]=0;
		}
		sort(Ke,Ke+N);
		int j;
		for(j=0;j<N;j++)
			if(Ke[j]!=Sa[j])break;
		if(j==N)return puts("YES"),0;
	}
	return puts("NO"),0;
}