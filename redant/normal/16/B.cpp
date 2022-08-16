#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

typedef pair<LL,LL> PLL;

vector< PLL > V;

int main()
{
	LL n,m,a,b,r=0,x,i,j,tot=0;

	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		V.push_back(make_pair(b,a) );
		tot+=a;
	}

	n = min(n,tot);
	sort(V.rbegin(),V.rend());
	i=0;
	while(n>0)
	{
		a=V[i].second; b=V[i].first;
		if(a>=n){ r+=n*b; break; }
		r+=a*b; n-=a; i++;
	}

	cout<<r<<endl;

	return 0;
}