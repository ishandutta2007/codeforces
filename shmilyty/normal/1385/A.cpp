#include<bits/stdc++.h>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a!=b&&a!=c&&b!=c)
			puts("No");
		else
		{
			if(b<a)
				swap(a,b);
			if(c<b)
				swap(c,b);
			if(b<a)
				swap(b,a);
			if(b!=c)
				puts("No");
			else
			{
				puts("Yes");
				cout<<a<<" "<<a<<" "<<b<<endl;
			}
		}
	}
	
	return 0;
}