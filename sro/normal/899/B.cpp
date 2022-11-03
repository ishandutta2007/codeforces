#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
string s,t;
int n,m;

int main()
{
	for(int i=0;i<3;i++)for(int j=0;j<12;j++)s+=a[j];
	for(int i=0;i<12;i++)s+=a[i]+(i==1);
	for(int i=0;i<3;i++)for(int j=0;j<12;j++)s+=a[j];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		t+=m;
	}
	if(s.find(t)!=string::npos)puts("YES");
	else puts("NO");
	return 0;
}