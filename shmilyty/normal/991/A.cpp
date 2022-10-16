#include<bits/stdc++.h>
#define no {cout<<-1;return 0;}
using namespace std;
int a,b,c,n;
int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&n);
	if(a<c||b<c)
		no
	int d=a+b-c;
	if(d>=n)
		no
	cout<<n-d;
	return 0;
}//2