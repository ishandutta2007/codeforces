#include<bits/stdc++.h>
using namespace std;
int t,l,r;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		if(l*2<=r)
			cout<<l<<" "<<2*l<<endl;
		else
			puts("-1 -1");
	}
	return 0;
}