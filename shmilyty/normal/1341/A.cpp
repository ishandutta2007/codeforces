#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d,l,r;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
		l=(a-b)*n;
		r=(a+b)*n;
		if(r<c-d||l>c+d)
			puts("NO");
		else
			puts("YES");
	}	
	return 0;
}