#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int s[123456];
bool xgl[123456];
int n;
int sum=0,cn3=0,cn1=0,cn2=0;
bool fgl(int a,int b)
{
	return a>b;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&s[i]);
	sort(s,s+n);
	sum+=upper_bound(s,s+n,4)-lower_bound(s,s+n,4);
	cn3=upper_bound(s,s+n,3)-lower_bound(s,s+n,3);
	cn1=upper_bound(s,s+n,1)-lower_bound(s,s+n,1)-cn3;
	cn1=(cn1<0)?0:cn1;
	sum+=cn3;
	cn2=upper_bound(s,s+n,2)-lower_bound(s,s+n,2);
	sum+=cn2/2;
	cn2%=2;
	cn1=cn2*2+cn1;
	sum+=cn1/4;
	if(cn1%4)sum++;
	printf("%d",sum);
	return 0;
}