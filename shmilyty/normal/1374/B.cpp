#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a=0,b=0;
		while(n%2==0)
		{
			a++;
			n/=2;
		}
		while(n%3==0)
		{
			b++;
			n/=3;
		}
		if(n!=1||a>b)
			puts("-1");
		else
			cout<<b*2-a<<endl; 
	}
	return 0;
}