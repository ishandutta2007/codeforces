#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		if(k>=n)
			cout<<k-n<<endl;
		else
			if((n-k)&1)
				puts("1");
			else
				puts("0");
	}
	return 0;
}