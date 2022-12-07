#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,w,sa=0,sb=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&w);sa+=w;
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&w);sb+=w;
	}
	if(sa>=sb) cout<<"Yes";
	else cout<<"No";
	return 0;
}