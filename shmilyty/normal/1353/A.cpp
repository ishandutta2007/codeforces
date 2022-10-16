#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1)
			puts("0");
		if(n==2)
			cout<<m<<endl;
		if(n>2)
			cout<<2*m<<endl; 
	}
	return 0;
} //1