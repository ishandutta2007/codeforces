#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,n,m,k,i,j,w;

	scanf("%d %d", &t, &k);
	++k;
	
	while(t--)
	{
		scanf("%d %d",&n,&m);

		if(n==1||m==1) w = 1-(max(n,m)&1);
		else
		{
			if(n%k==0 && m>=n) w=1;
			else if(m%k==0 && n>=m) w=1;
			else
			{
				w = (n&1) ? 1-(m&1) : (m&1);
				if(k>2 && n>k && m>k) if((min(n,m)/k)&1) w=1-w;
			}
		}

		if(w) printf("+\n"); else printf("-\n");
	}

	return 0;
}