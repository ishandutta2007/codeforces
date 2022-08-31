#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	LL a,b,x,y,c,d,k,l,h,m,g;
	cin>>a>>b>>x>>y;
	
	g=__gcd(x,y);
	x/=g; y/=g;

	l = 0; h = a/x;
	while(l<h)
	{
		m = l + (h-l+1)/2;
		if(x*m<=a && y*m<=b) l=m;
		else h=m-1;
	}

	cout<<x*l<<" "<<y*l<<endl;

	return 0;
}