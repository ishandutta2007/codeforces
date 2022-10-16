#include<bits/stdc++.h>//1
using namespace std;
int sum=0,maxx=0,n,a,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum+=a;
			maxx=max(maxx,a); 
		}
		if(sum-maxx<maxx||sum&1)
			puts("T");
		else
			puts("HL");
	}
    return 0;
}