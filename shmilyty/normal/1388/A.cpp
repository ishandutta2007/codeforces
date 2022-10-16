#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=30)
			puts("No");
		else
		{
			puts("Yes");
			if(n==36||n==40||n==44)
				cout<<6<<" "<<10<<" "<<15<<" "<<n-31<<endl;
			else
				cout<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
		}
	}
	return 0;
}