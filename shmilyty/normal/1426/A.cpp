#include<bits/stdc++.h>//1
using namespace std;
int t,n,x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&x);
		if(n<=2)
		{
			puts("1");
			continue;
		}
		n-=2;
		cout<<(n+x-1)/x+1<<endl;
	}	
	return 0;
}