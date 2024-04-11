#include<bits/stdc++.h>
using namespace std;
int x,y,z,cnt,p1,p2,p3;
int main()
{
	int i,a,b;
	cin>>x>>y>>z;
	for(i=0;i<=z;i++)
	{
		a=x+i;b=y+z-i;
		if(a>b) p1=1;
		if(a==b) p2=1;
		if(a<b) p3=1;
	}
	if(p1) cnt++;
	if(p2) cnt++;
	if(p3) cnt++;
	if(cnt>1) puts("?");
	else if(p1) puts("+");
	else if(p2) puts("0");
	else puts("-");
}