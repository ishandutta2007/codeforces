#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	int d = 0;
	int c = m;
	while(c>0)
	{
		d++;
		c=c/2;
	}
	if (n>=d) printf("%d\n",m);
	else printf("%d\n",m%(1<<n));
	return 0;
}