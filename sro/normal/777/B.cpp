#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXD=10;

string s1,s2;
int n,fre[MAXD],tk[MAXD],cn1,cn2;

int Get(int dig)
{
	while(dig>=0&&tk[dig]>=fre[dig])dig--;
	if(dig>=0){tk[dig]++;return true;}
	return false;
}

int main()
{
	cin>>n>>s1>>s2;
	for(int i=0;i<n;i++)fre[s1[i]-'0']++;
	for(int i=0;i<n;i++)
		if(!Get(s2[i]-'0'))cn1++;
	fill(tk,tk+MAXD,0);
	for(int i=0;i<n;i++)
		if(Get(s2[i]-'0'-1))cn2++;
	printf("%d\n%d\n",cn1,cn2);
	return 0;
}