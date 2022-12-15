#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

//s.max_load_factor(0.25);s.reserve(2048);

int main ()
{
	long long n,m,i,j;

	cin>>n>>m;

	int suma,sumb;
	string a,b;

	a="5";
	b="5";

	suma=5;
	sumb=5;

	while(n>sumb)
	{
		a="5"+a;
		b="4"+b;
		sumb+=4;
		suma+=5;
	}

	cout<<a<<" "<<b<<endl;

	return 0;
}