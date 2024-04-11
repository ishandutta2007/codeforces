#include<iostream>
#include<cstdio>
using namespace std;
int h,m,s;
int t1,t2;
int col[13];
int main()
{
	cin>>h>>m>>s>>t1>>t2;
	m/=5;
	if(m==0)m=12;
	s/=5; 
	if(s==0)s=12;
	int cur=h+1,c=1;
	if(cur>12)cur=1;
	for(int i=1;i<=12;i++)
	{
		col[cur]=c;
		if(cur==m)c=2;
		if(cur==s)c=3;
		cur++;
		if(cur>12)cur=1;
	}
	printf((col[t1]==col[t2])?"YES":"NO");
	return 0;
}